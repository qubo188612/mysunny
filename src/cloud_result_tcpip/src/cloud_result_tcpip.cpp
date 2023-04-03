#include "cloud_result_tcpip/cloud_result_tcpip.hpp"
#include <cstdio>

namespace cloud_result_tcpip
{
TCPServer clouldresulttcp;
pthread_t msg1[MAX_CLIENT];
int num_message = 0;
volatile int b_fuzhi;
volatile int b_updatafinish;
tutorial_interfaces::msg::IfAlgorhmitcloud rcvmsg;
volatile int b_open;

Cloud_Result_Tcpip::Cloud_Result_Tcpip(const rclcpp::NodeOptions & options)
: Node("cloud_result_tcpip_node", options)
{
    b_fuzhi=0;
    b_updatafinish=0;
    b_open=0;

    b_tcpsockershow=false;
    this->declare_parameter("b_tcpsockershow",false);

    this->declare_parameter("clould_result_port", 1499);  //clould_result_port协议端口
    clould_result_port = this->get_parameter("clould_result_port").as_int(); 

    num_cloudresultclient=0;
    _cloudresulttcpthread = std::thread(&Cloud_Result_Tcpip::_cloudresult, this, clould_result_port);

    subscription_cloud_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>(
        _sub_cloudresult_name, rclcpp::SensorDataQoS(), std::bind(&Cloud_Result_Tcpip::cloud_result_callback, this, _1));
/*
Json::Value sent_root;
Json::Value header;
Json::Value stamp;
Json::Value lasertrackoutcloud;
Json::Value cloud;
Json::Value targetpointoutcloud;
Json::Value tarpoint;
Json::Value solderjoints;
stamp["sec"]=1;
stamp["nanosec"]=2;
header["stamp"]=stamp;
header["frame_id"]="rcvmsg.header.frame_id";
sent_root["header"]=header;
for(int i=0;i<3;i++)
{
    cloud["x"]=1.1;
    cloud["y"]=2.2;
    cloud["u"]=3;
    cloud["v"]=4;
    lasertrackoutcloud.append(cloud);
}
sent_root["lasertrackoutcloud"]=lasertrackoutcloud;
for(int i=0;i<3;i++)
{
    tarpoint["x"]=1.1;
    tarpoint["y"]=2.2;
    tarpoint["u"]=3;
    tarpoint["v"]=4;
    tarpoint["name"]="point1";
    targetpointoutcloud.append(tarpoint);
}
sent_root["targetpointoutcloud"]=targetpointoutcloud;
sent_root["solderjoints"]=true;
Json::StreamWriterBuilder builder;
std::string json_file=Json::writeString(builder, sent_root);
cerr << "message: " << json_file << endl;
*/

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "b_tcpsockershow") {
            b_tcpsockershow=p.as_bool();
            return result;
        } 
      }
      return result;
    }
  );

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

Cloud_Result_Tcpip::~Cloud_Result_Tcpip()
{
  _cloudresulttcpthread.join();  
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
        rcvmsg=msg;
        
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
            if(b_updatafinish==1&&b_open==1)
            {
                Json::Value sent_root;
                Json::Value header;
                Json::Value stamp;
                Json::Value lasertrackoutcloud;
                Json::Value cloud;
                Json::Value targetpointoutcloud;
                Json::Value tarpoint;
                Json::Value solderjoints;
                stamp["sec"]=rcvmsg.header.stamp.sec;
                stamp["nanosec"]=rcvmsg.header.stamp.nanosec;
                header["stamp"]=stamp;
                header["frame_id"]=rcvmsg.header.frame_id;
                sent_root["header"]=header;
                for(int i=0;i<rcvmsg.lasertrackoutcloud.size();i++)
                {
                    cloud["x"]=rcvmsg.lasertrackoutcloud[i].x;
                    cloud["y"]=rcvmsg.lasertrackoutcloud[i].y;
                    cloud["u"]=rcvmsg.lasertrackoutcloud[i].u;
                    cloud["v"]=rcvmsg.lasertrackoutcloud[i].v;
                    lasertrackoutcloud.append(cloud);
                }
                sent_root["lasertrackoutcloud"]=lasertrackoutcloud;
                for(int i=0;i<rcvmsg.targetpointoutcloud.size();i++)
                {
                    tarpoint["x"]=rcvmsg.targetpointoutcloud[i].x;
                    tarpoint["y"]=rcvmsg.targetpointoutcloud[i].y;
                    tarpoint["u"]=rcvmsg.targetpointoutcloud[i].u;
                    tarpoint["v"]=rcvmsg.targetpointoutcloud[i].v;
                    tarpoint["name"]=rcvmsg.targetpointoutcloud[i].name;
                    targetpointoutcloud.append(tarpoint);
                }
                sent_root["targetpointoutcloud"]=targetpointoutcloud;
                sent_root["solderjoints"]=rcvmsg.solderjoints;
                if(sent_root.size()!=0)
                {
                    Json::StreamWriterBuilder builder;
                    std::string json_file=Json::writeString(builder, sent_root);
                    if(!clouldresulttcp.is_online() && clouldresulttcp.get_last_closed_sockets() == desc->id) 
                    {
                        cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->id << " )"<< endl;
                    }
                    clouldresulttcp.Send(json_file, desc->id);
                    if(b_tcpsockershow==true)
                    {  
                      cerr << "message: " << json_file << endl;
                    }
                }

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
                if(_p->desc_cloudresult[i]->message[0]==1)
                {
                    b_open=1;
                    cerr << "open_cloudresult_tcp"<< endl;
                }
                else if(_p->desc_cloudresult[i]->message[0]==0)
                {
                    b_open=0;
                    cerr << "close_cloudresult_tcp"<< endl;
                }
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
