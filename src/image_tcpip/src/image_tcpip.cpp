#include "image_tcpip/image_tcpip.hpp"
#include <cstdio>

namespace image_tcpip
{
TCPServer imagetcp;
pthread_t msg1[MAX_CLIENT];
int num_message = 0;
cv::Mat cv_image;
volatile int b_fuzhi;
volatile int b_updatafinish;

Image_Tcpip::Image_Tcpip(const rclcpp::NodeOptions & options)
: Node("image_tcpip_node", options)
{
    b_fuzhi=0;
    b_updatafinish=0;
    ptr_cv_image=&cv_image;

    this->declare_parameter("image_port", 1497);  //image_port协议端口
    image_port = this->get_parameter("image_port").as_int(); 

    num_imageclient=0;
    _imagetcpthread = std::thread(&Image_Tcpip::_image, this, image_port);

    subscription_image = this->create_subscription<sensor_msgs::msg::Image>(
        _sub_name, rclcpp::SensorDataQoS(), std::bind(&Image_Tcpip::image_callback, this, _1));
}

Image_Tcpip::~Image_Tcpip()
{
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

int Image_Tcpip::encoding2mat_type(std::string encoding) const 
{
    if(encoding=="mono8")
    {
        return CV_8UC1;
    }
    else if(encoding=="bgr8")
    {
        return CV_8UC3;
    }
    else if(encoding=="mono16")
    {
        return CV_16SC1;
    }
    else if(encoding=="rgba8")
    {
        return CV_8UC4;
    }
    else 
    {
        return CV_8UC1;
    }
}

void Image_Tcpip::image_callback(const sensor_msgs::msg::Image msg)  const
{
    cv::Mat src(msg.height, msg.width, encoding2mat_type(msg.encoding),(char*)msg.data.data()); 
    if(b_fuzhi==0)
    {
        b_fuzhi=1;
        (*ptr_cv_image)=src.clone();
        b_fuzhi=0;
        b_updatafinish=1;
    }
}


void Image_Tcpip::_image(int port)
{  
    pthread_t msg;
    std::signal(SIGINT, close_imagetcp);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( imagetcp.setup(port,opts) != 0)
    {
         RCLCPP_ERROR(this->get_logger(), "Errore imagetcp socket.");
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Open imagetcp socket.");
        if( pthread_create(&msg, NULL, received_imagetcp, this) == 0)
        {
            while(rclcpp::ok()) {
                imagetcp.accepted();
                cerr << "imagetcp Accepted" << endl;
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Errore imagetcp thread socket.");
        }
    }   
}

void close_imagetcp(int s) 
{
    imagetcp.closed();
    rclcpp::shutdown();
}

void * send_client(void * m) {
        struct descript_socket *desc = (struct descript_socket*) m;

	while(1) {
		if(!imagetcp.is_online() && imagetcp.get_last_closed_sockets() == desc->id) {
			cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->ip << " )"<< endl;
			break;
		}
        /*
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		int hour = now->tm_hour;
		int min  = now->tm_min;
		int sec  = now->tm_sec;

		std::string date = 
			    to_string(now->tm_year + 1900) + "-" +
			    to_string(now->tm_mon + 1)     + "-" +
			    to_string(now->tm_mday)        + " " +
			    to_string(hour)                + ":" +
			    to_string(min)                 + ":" +
			    to_string(sec)                 + "\r\n";
		cerr << date << endl;
		imagetcp.Send(date, desc->id);
        */
        if(b_fuzhi==0)
        {
            b_fuzhi=1;
            if (!cv_image.empty())    //如果照片为空则退出
            {
                if(b_updatafinish==1)
                {
                    std::vector<uchar> data_encode;
                    std::vector<int> quality;
                    quality.push_back(cv::IMWRITE_JPEG_QUALITY);
                    quality.push_back(1);//进行50%的压缩
                    cv::imencode(".webp", cv_image, data_encode,quality);//将图像编码
                    imagetcp.Send((char*)data_encode.data(),data_encode.size(),desc->id);
                    b_updatafinish=0;
                }
            }
            b_fuzhi=0;
        }
		sleep(0);
	}
	pthread_exit(NULL);
	return 0;
}

void* received_imagetcp(void *m)
{
    Image_Tcpip *_p=(Image_Tcpip*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->desc_image = imagetcp.getMessage();
        for(unsigned int i = 0; i < _p->desc_image.size(); i++) 
        {
            if( _p->desc_image[i] )
            {
                if(!_p->desc_image[i]->enable_message_runtime) 
				{
					_p->desc_image[i]->enable_message_runtime = true;
			                if( pthread_create(&msg1[num_message], NULL, send_client, (void *) _p->desc_image[i]) == 0) {
						cerr << "ATTIVA THREAD INVIO MESSAGGI" << endl;
					}
					num_message++;
					// start message background thread
				}

                std::vector<char> vec=_p->desc_image[i]->message;
                vec.push_back('\0');
                std::string str(vec.begin(), vec.end());

            #ifdef SHOW_TCPSOCK_RECEIVE  
                cerr << "id:      " << _p->desc_image[i]->id      << endl
                    << "ip:      " << _p->desc_image[i]->ip      << endl
                    << "message: " << _p->desc_image[i]->message << endl
                    << "socket:  " << _p->desc_image[i]->socket  << endl
                    << "enable:  " << _p->desc_image[i]->enable_message_runtime << endl;
            #endif

                imagetcp.clean(i);
            }
        }
        sleep(0);
    }
    return 0;
}

}

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(image_tcpip::Image_Tcpip)
