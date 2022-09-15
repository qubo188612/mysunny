#ifndef CAMERA_TIS__CAMERA_TEST_HPP_
#define CAMERA_TIS__CAMERA_TEST_HPP_

#include "rclcpp/rclcpp.hpp"
#include <rclcpp/rclcpp.hpp>
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include <modbus.h>
#include <unistd.h>

#define SHOW_OUTPUT_FPS

namespace camera_test
{

using sensor_msgs::msg::Image;

class CameraTest : public rclcpp::Node
{
public:

     /**
   * @brief Construct a new Camera Tis object.
   *
   * Initialize publisher.
   * Create an inner implementation.
   * Print success if all done.
   * @param options Encapsulation of options for node initialization.
   */
  explicit CameraTest(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  /**
   * @brief Destroy the Camera Tis object.
   *
   * Release inner implementation.
   * Release publisher.
   * Print success if all done.
   * Throw no exception.
   */
  virtual ~CameraTest();

  rclcpp::Publisher<Image>::SharedPtr _pub;

  cv::Mat cv_image;

  std::string mat_type2encoding(int mat_type);

#ifdef SHOW_OUTPUT_FPS
  modbus_t * ctx;
  void _modbus(int port);
  bool b_modbusconnect;
  std::thread _threadmodbus;
#endif
  
private:
  /**
   * @brief Publisher name.
   *
   */
  const char * _pub_name = "~/image";

  rclcpp::TimerBase::SharedPtr timer_;


};

void timer_callback();

static CameraTest *pThis;

}

#endif