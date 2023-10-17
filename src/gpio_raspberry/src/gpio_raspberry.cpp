// Copyright 2019 Zhushi Tech, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gpio_raspberry/gpio_raspberry.hpp"

#include <gpiod.h>

#include <vector>

namespace gpio_raspberry
{

using rcl_interfaces::msg::ParameterDescriptor;
using rcl_interfaces::msg::SetParametersResult;

GpioRaspberry::GpioRaspberry(const rclcpp::NodeOptions & options)
: Node("gpio_raspberry_node", options),
  _chip0(gpiod_chip_open_by_name(GPIO_CHIP_NAME_0), gpiod_chip_close),
  _line_leaser0(gpiod_chip_get_line(_chip0.get(), GPIO_LEASER_LIGHT_0), gpiod_line_release),   //激光器
  _line_power0(gpiod_chip_get_line(_chip0.get(), GPIO_POWER_LIGHT_0), gpiod_line_release),     //指示灯
  _chip1(gpiod_chip_open_by_name(GPIO_CHIP_NAME_1), gpiod_chip_close),
  _line_leaser1(gpiod_chip_get_line(_chip1.get(), GPIO_LEASER_LIGHT_1), gpiod_line_release),   //激光器
  _line_power1(gpiod_chip_get_line(_chip1.get(), GPIO_POWER_LIGHT_1), gpiod_line_release)     //指示灯
{
  // To enforce start with laser off
  this->declare_parameter("laser", false, ParameterDescriptor(), true);

  gpiod_line_request_output(_line_leaser0.get(), "ros", 0);  //设置输出，初始0
  gpiod_line_request_output(_line_power0.get(), "ros", 1);   //设置输出，初始0

  gpiod_line_request_output(_line_leaser1.get(), "ros", 0);  //设置输出，初始0
  gpiod_line_request_output(_line_power1.get(), "ros", 1);   //设置输出，初始0

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "laser") {
          auto ret = this->_laser(p.as_bool());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set laser";
            return result;
          }
        }
      }
      return result;
    });

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

GpioRaspberry::~GpioRaspberry()
{
  try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

int GpioRaspberry::_laser(bool f)
{
  int rc0;
  int rc1;
  if (f) { 
     rc0=gpiod_line_set_value(_line_leaser0.get(), 1);
     rc1=gpiod_line_set_value(_line_leaser1.get(), 1);
     return(rc0||rc1);
  } else {
     rc0=gpiod_line_set_value(_line_leaser0.get(), 0);
     rc1=gpiod_line_set_value(_line_leaser1.get(), 0);
     return(rc0||rc1);
  }
}

}  // namespace gpio_raspberry

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(gpio_raspberry::GpioRaspberry)
