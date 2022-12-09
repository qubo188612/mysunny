#include "cloud_result_tcpip/cloud_result_tcpip.hpp"
#include <cstdio>

namespace cloud_result_tcpip
{
TCPServer clouldresulttcp;
pthread_t msg1[MAX_CLIENT];
int num_message = 0;
volatile int b_fuzhi;
volatile int b_updatafinish;

Cloud_Result_Tcpip::Cloud_Result_Tcpip(const rclcpp::NodeOptions & options)
: Node("cloud_result_tcpip_node", options)
{
    b_fuzhi=0;
    b_updatafinish=0;
    this->declare_parameter("clould_result_port", 1499);  //clould_result_port协议端口
    clould_result_port = this->get_parameter("clould_result_port").as_int(); 

    num_cloudresultclient=0;
    _cloudresulttcpthread = std::thread(&Cloud_Result_Tcpip::_cloudresult, this, clould_result_port);

    subscription_cloud_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>(
        _sub_cloudresult_name, rclcpp::SensorDataQoS(), std::bind(&Cloud_Result_Tcpip::cloud_result_callback, this, _1));
}

Cloud_Result_Tcpip::~Cloud_Result_Tcpip()
{
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}
void Cloud_Result_Tcpip::cloud_result_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)  const
{
    if(b_fuzhi==0)
    {
        b_fuzhi=1;


        b_fuzhi=0;
        b_updatafinish=1;
    } 
}

void Cloud_Result_Tcpip::_cloudresult(int port)
{
    pthread_t msg;
    std::signal(SIGINT, close_cloudresulttcp);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( clouldresulttcp.setup(port,opts) != 0)
    {
         RCLCPP_ERROR(this->get_logger(), "Errore close_cloudresulttcp socket.");
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Open close_cloudresulttcp socket.");
        if( pthread_create(&msg, NULL, received_cloudresulttcp, this) == 0)
        {
            while(rclcpp::ok()) {
                clouldresulttcp.accepted();
                cerr << "close_cloudresulttcp Accepted" << endl;
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Errore close_cloudresulttcp thread socket.");
        }
    } 
}

void close_cloudresulttcp(int s) 
{
    clouldresulttcp.closed();
    rclcpp::shutdown();
}

void * send_client(void * m) {
        struct descript_socket *desc = (struct descript_socket*) m;

	while(1) {
		if(!clouldresulttcp.is_online() && clouldresulttcp.get_last_closed_sockets() == desc->id) {
			cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->ip << " )"<< endl;
			break;
		}

        if(b_fuzhi==0)
        {
            b_fuzhi=1;
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
            clouldresulttcp.Send(date, desc->id);
            */
            if(b_updatafinish==1)
            {

                
                b_updatafinish=0;
            }
            b_fuzhi=0;
        }
		sleep(0);
	}
	pthread_exit(NULL);
	return 0;
}

void* received_cloudresulttcp(void *m)
{
    Cloud_Result_Tcpip *_p=(Cloud_Result_Tcpip*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->desc_cloudresult = clouldresulttcp.getMessage();
        for(unsigned int i = 0; i < _p->desc_cloudresult.size(); i++) 
        {
            if( _p->desc_cloudresult[i] )
            {
                if(!_p->desc_cloudresult[i]->enable_message_runtime) 
                {
                  _p->desc_cloudresult[i]->enable_message_runtime = true;
                              if( pthread_create(&msg1[num_message], NULL, send_client, (void *) _p->desc_cloudresult[i]) == 0) {
                    cerr << "ATTIVA THREAD INVIO MESSAGGI" << endl;
                  }
                  num_message++;
                  // start message background thread
                }
                
                std::vector<char> vec=_p->desc_cloudresult[i]->message;
                vec.push_back('\0');
                std::string str(vec.begin(), vec.end());
            #ifdef SHOW_TCPSOCK_RECEIVE 
                cerr << "id:      " << _p->desc_cloudresult[i]->id      << endl
                    << "ip:      " << _p->desc_cloudresult[i]->ip      << endl
                    << "message: " << str << endl
                    << "socket:  " << _p->desc_cloudresult[i]->socket  << endl
                    << "enable:  " << _p->desc_cloudresult[i]->enable_message_runtime << endl;
            #endif
                
                clouldresulttcp.clean(i);
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
RCLCPP_COMPONENTS_REGISTER_NODE(cloud_result_tcpip::Cloud_Result_Tcpip)
