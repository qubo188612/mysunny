#ifndef CAMERA_TIS__CAMERA_TEST_HPP_
#define CAMERA_TIS__CAMERA_TEST_HPP_

#include "rclcpp/rclcpp.hpp"
#include <rclcpp/rclcpp.hpp>
#include "opencv2/opencv.hpp"
#include <modbus.h>
#include <unistd.h>
#include <opencv2/videoio/videoio.hpp>
#include "tutorial_interfaces/msg/if_algorhmitimage.hpp"
#include "tutorial_interfaces/msg/if_algorhmitrobpos.hpp"

#define SHOW_OUTPUT_FPS

//#define TEST_VIDEO        //输入视频测试

#define PIC_IMAGE_HEIGHT 1536
#define PIC_IMAGE_WIDTH  1024

namespace camera_test
{

using std::placeholders::_1;
using tutorial_interfaces::msg::IfAlgorhmitimage;

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

  rclcpp::Publisher<IfAlgorhmitimage>::SharedPtr _pub;

  cv::Mat cv_image;

  cv::VideoCapture capture;

  std::string mat_type2encoding(int mat_type);

#ifdef SHOW_OUTPUT_FPS
  modbus_t * ctx;
  void _modbus(int port);
  bool b_modbusconnect;
  std::thread _threadmodbus;
#endif

  const char * _sub_robposresult_name = "~/input_robpos";

  rclcpp::Subscription<tutorial_interfaces::msg::IfAlgorhmitrobpos>::SharedPtr subcription_pos_result;

  void robpos_result_callback(const tutorial_interfaces::msg::IfAlgorhmitrobpos msg);

  
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