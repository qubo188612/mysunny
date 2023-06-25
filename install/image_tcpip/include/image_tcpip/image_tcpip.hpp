#ifndef IMAGE_TCPIP__IMAGETCPIP_HPP_
#define IMAGE_TCPIP__IMAGETCPIP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include <TCP/TCPServer.h>
#include "opencv2/imgcodecs/legacy/constants_c.h"

namespace image_tcpip
{

using std::placeholders::_1;
using sensor_msgs::msg::Image;

class Image_Tcpip : public rclcpp::Node
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
    explicit Image_Tcpip(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

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
    virtual ~Image_Tcpip();

    vector<descript_socket*> desc_image;

private:

    const char * _sub_name = "~/image";

    int image_port;

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_image;

    void image_callback(const sensor_msgs::msg::Image msg)  const;


    int encoding2mat_type(std::string encoding) const;
    
    cv::Mat *ptr_cv_image;

    //tcp number of client
    int num_imageclient;
    std::thread _imagetcpthread;

    void _image(int);
};

void close_imagetcp(int s);
void* send_client(void * m);
void* received_imagetcp(void * m);

}

#endif