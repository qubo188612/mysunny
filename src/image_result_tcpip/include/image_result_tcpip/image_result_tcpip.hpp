#ifndef IMAGE_RESULT_TCPIP__IMAGERESULTTCPIP_HPP_
#define IMAGE_RESULT_TCPIP__IMAGERESULTTCPIP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/if_algorhmitmsg.hpp"
#include "opencv2/opencv.hpp"
#include <TCP/TCPServer.h>
#include "opencv2/imgcodecs/legacy/constants_c.h"

namespace image_result_tcpip
{

using std::placeholders::_1;
using tutorial_interfaces::msg::IfAlgorhmitmsg;

class Image_Result_Tcpip : public rclcpp::Node
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
    explicit Image_Result_Tcpip(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

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
    virtual ~Image_Result_Tcpip();

    vector<descript_socket*> desc_imageresult;

private:

    const char * _sub_result_name = "~/result";

    int image_result_port;


    rclcpp::Subscription<tutorial_interfaces::msg::IfAlgorhmitmsg>::SharedPtr subscription_image_result;


    void image_result_callback(const tutorial_interfaces::msg::IfAlgorhmitmsg msg)  const;

    int encoding2mat_type(std::string encoding) const;

    cv::Mat *ptr_cv_image_result;

    //tcp number of client

    int num_imageresultclient;
    std::thread _imageresulttcpthread;

    void _imageresult(int);
};

void close_imageresulttcp(int s);
void* send_client(void * m);
void* received_imageresulttcp(void * m);

}

#endif