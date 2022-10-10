#ifndef CLOUD_RESULT_TCPIP__CLOUDRESULTTCPIP_HPP_
#define CLOUD_RESULT_TCPIP__CLOUDRESULTTCPIP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/if_algorhmitcloud.hpp"
#include "opencv2/opencv.hpp"
#include <TCP/TCPServer.h>

namespace cloud_result_tcpip
{

using std::placeholders::_1;
using tutorial_interfaces::msg::IfAlgorhmitcloud;

class Cloud_Result_Tcpip : public rclcpp::Node
{
public:
    /**
     * @brief Construct a new Laser Line Center object.
     *
     * Initialize publisher.
     * Create an inner implementation.
     * Initialize subscription.
     * Print success if all done.
     * @param options Encapsulation of options for node initialization.
     */
    explicit Cloud_Result_Tcpip(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

    /**
     * @brief Destroy the Laser Line Center object.
     *
     * Release subscription.
     * Wake up all workers.
     * Wake up the manager.
     * Synchronize with all threads, wait for its return.
     * Release publisher.
     * Print success if all done.
     * Throw no exception.
     */
    virtual ~Cloud_Result_Tcpip();

    vector<descript_socket*> desc_cloudresult;

private:

    const char * _sub_cloudresult_name = "~/cloudresult";

    int clould_result_port;

    rclcpp::Subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>::SharedPtr subscription_cloud_result;

    void cloud_result_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)  const;

    int num_cloudresultclient;
    std::thread _cloudresulttcpthread;

    void _cloudresult(int);
};

void close_cloudresulttcp(int s);
void* send_client(void * m);
void* received_cloudresulttcp(void * m);

}

#endif