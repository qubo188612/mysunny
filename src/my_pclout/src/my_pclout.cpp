#include "my_pclout/my_pclout.hpp"
#include <cstdio>

namespace my_pclout
{

My_Pclout::My_Pclout(const rclcpp::NodeOptions & options)
: Node("my_pclout_node", options)
{
    
}

My_Pclout::~My_Pclout()
{
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

}