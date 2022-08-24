#include "camera_test/camera_test.hpp"

#include <cstdio>

namespace camera_test
{
using namespace std::chrono_literals;

using rcl_interfaces::msg::ParameterDescriptor;
using rcl_interfaces::msg::SetParametersResult;

void timer_callback()
{ 
  if(!pThis->cv_image.empty())
  {
    sensor_msgs::msg::Image::UniquePtr image_msg(new sensor_msgs::msg::Image());
    auto stamp = pThis->now();
    image_msg->header.stamp = stamp;
    image_msg->header.frame_id = "my_eyesId";
    image_msg->height = pThis->cv_image.rows;
    image_msg->width = pThis->cv_image.cols;
    image_msg->encoding = pThis->mat_type2encoding(pThis->cv_image.type());
    image_msg->is_bigendian = false;
    image_msg->step = static_cast<sensor_msgs::msg::Image::_step_type>(pThis->cv_image.step);
    image_msg->data.assign(pThis->cv_image.datastart, pThis->cv_image.dataend);

    pThis->_pub->publish(std::move(image_msg));
  }
}

CameraTest::CameraTest(const rclcpp::NodeOptions & options)
: Node("camera_tis_node", options)
{
  pThis=this;
  _pub = this->create_publisher<Image>(_pub_name, rclcpp::SensorDataQoS());
  timer_ = this->create_wall_timer(25ms, std::bind(&camera_test::timer_callback));
  cv_image = cv::imread("/home/qubo/mysunny/src/camera_test/bmp/test3.bmp");
  cv::cvtColor(cv_image, cv_image, cv::COLOR_BGR2GRAY);

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

CameraTest::~CameraTest()
{
  try {
    _pub.reset();

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}

std::string CameraTest::mat_type2encoding(int mat_type)
{
  switch (mat_type) {
    case CV_8UC1:
      return "mono8";
    case CV_8UC3:
      return "bgr8";
    case CV_16SC1:
      return "mono16";
    case CV_8UC4:
      return "rgba8";
    default:
      throw std::runtime_error("unsupported encoding type");
  }
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(camera_test::CameraTest)