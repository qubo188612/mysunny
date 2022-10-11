#include "image_result_tcpip/image_result_tcpip.hpp"
#include <cstdio>

namespace image_result_tcpip
{
TCPServer imageresulttcp;
pthread_t msg1[MAX_CLIENT];
int num_message = 0;
cv::Mat cv_image_result;
volatile int b_fuzhi;
volatile int b_updatafinish;
volatile int b_open;

Image_Result_Tcpip::Image_Result_Tcpip(const rclcpp::NodeOptions & options)
: Node("image_result_tcpip_node", options)
{
    b_fuzhi=0;
    b_updatafinish=0;
    b_open=0;
    ptr_cv_image_result=&cv_image_result;

    this->declare_parameter("image_result_port", 1498);  //image_result_port协议端口
    image_result_port = this->get_parameter("image_result_port").as_int(); 

    num_imageresultclient=0;
    _imageresulttcpthread = std::thread(&Image_Result_Tcpip::_imageresult, this, image_result_port);

    subscription_image_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitmsg>(
        _sub_result_name, rclcpp::SensorDataQoS(), std::bind(&Image_Result_Tcpip::image_result_callback, this, _1));
}

Image_Result_Tcpip::~Image_Result_Tcpip()
{
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

int Image_Result_Tcpip::encoding2mat_type(std::string encoding) const 
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


void Image_Result_Tcpip::image_result_callback(const tutorial_interfaces::msg::IfAlgorhmitmsg msg)  const
{
    cv::Mat src(msg.imageout.height, msg.imageout.width, encoding2mat_type(msg.imageout.encoding), (char*)msg.imageout.data.data());
    if(b_fuzhi==0)
    {
        b_fuzhi=1;
        (*ptr_cv_image_result)=src.clone();
        b_fuzhi=0;
        b_updatafinish=1;
    } 
}

void Image_Result_Tcpip::_imageresult(int port)
{
    pthread_t msg;
    std::signal(SIGINT, close_imageresulttcp);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( imageresulttcp.setup(port,opts) != 0)
    {
         RCLCPP_ERROR(this->get_logger(), "Errore imageresulttcp socket.");
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Open imageresulttcp socket.");
        if( pthread_create(&msg, NULL, received_imageresulttcp, this) == 0)
        {
            while(rclcpp::ok()) {
                imageresulttcp.accepted();
                cerr << "imageresulttcp Accepted" << endl;
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Errore imageresulttcp thread socket.");
        }
    } 
}

void close_imageresulttcp(int s) 
{
    imageresulttcp.closed();
    rclcpp::shutdown();
}

void * send_client(void * m) {
        struct descript_socket *desc = (struct descript_socket*) m;
	while(1) {
		if(!imageresulttcp.is_online() && imageresulttcp.get_last_closed_sockets() == desc->id) {
			cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->ip << " )"<< endl;
			break;
		}
        if(b_fuzhi!=0)
            continue;
        b_fuzhi=1;
        if (!cv_image_result.empty())    //如果照片为空则退出
		{
            if(b_updatafinish==1&&b_open==1)
            {
                std::vector<uchar> data_encode;
                std::vector<int> quality;
                quality.push_back(cv::IMWRITE_JPEG_QUALITY);
                if(cv_image_result.rows>384&&cv_image_result.cols>256)
                {
                    quality.push_back(50);//进行50%的压缩
                }
                else
                {
                    quality.push_back(100);//进行50%的压缩
                }
                cv::imencode(".jpg", cv_image_result, data_encode,quality);//将图像编码
                imageresulttcp.Send((char*)data_encode.data(),data_encode.size(),desc->id);
                b_updatafinish=0;
            }
            /*
            std::vector<uchar> data_encode;
            data_encode.resize(5);
            data_encode[0]=cv_image_result.channels();
            data_encode[1]=(cv_image_result.cols>>8);
            data_encode[2]=(cv_image_result.cols&0x00ff);
            data_encode[3]=(cv_image_result.rows>>8);
            data_encode[4]=(cv_image_result.rows&0x00ff);
            data_encode.insert(data_encode.end(), cv_image_result.data, 
                                cv_image_result.data + cv_image_result.cols*cv_image_result.rows*cv_image_result.channels());
            imageresulttcp.Send((char*)data_encode.data(),data_encode.size(),desc->id);
            */
		}
        b_fuzhi=0;
		sleep(0);
	}
	pthread_exit(NULL);
	return 0;
}

void* received_imageresulttcp(void *m)
{
    Image_Result_Tcpip *_p=(Image_Result_Tcpip*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->desc_imageresult = imageresulttcp.getMessage();
        for(unsigned int i = 0; i < _p->desc_imageresult.size(); i++) 
        {
            if( _p->desc_imageresult[i] )
            {
                if(!_p->desc_imageresult[i]->enable_message_runtime) 
                {
                  _p->desc_imageresult[i]->enable_message_runtime = true;
                              if( pthread_create(&msg1[num_message], NULL, send_client, (void *) _p->desc_imageresult[i]) == 0) {
                    cerr << "ATTIVA THREAD INVIO MESSAGGI" << endl;
                  }
                  num_message++;
                  // start message background thread
                }
                cerr << "id:      " << _p->desc_imageresult[i]->id      << endl
                    << "ip:      " << _p->desc_imageresult[i]->ip      << endl
                    << "message: " << _p->desc_imageresult[i]->message << endl
                    << "socket:  " << _p->desc_imageresult[i]->socket  << endl
                    << "enable:  " << _p->desc_imageresult[i]->enable_message_runtime << endl;
                if(_p->desc_imageresult[i]->message[0]==1)
                {
                    b_open=1;
                    cerr << "open_imgresult_tcp"<< endl;
                }
                else if(_p->desc_imageresult[i]->message[0]==0)
                {
                    b_open=0;
                    cerr << "close_imgresult_tcp"<< endl;
                }
                
                imageresulttcp.clean(i);
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
RCLCPP_COMPONENTS_REGISTER_NODE(image_result_tcpip::Image_Result_Tcpip)
