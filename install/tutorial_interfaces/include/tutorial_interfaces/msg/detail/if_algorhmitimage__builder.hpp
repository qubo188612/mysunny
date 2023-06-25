// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitimage__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitimage_robpos
{
public:
  explicit Init_IfAlgorhmitimage_robpos(::tutorial_interfaces::msg::IfAlgorhmitimage & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitimage robpos(::tutorial_interfaces::msg::IfAlgorhmitimage::_robpos_type arg)
  {
    msg_.robpos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitimage msg_;
};

class Init_IfAlgorhmitimage_image
{
public:
  Init_IfAlgorhmitimage_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitimage_robpos image(::tutorial_interfaces::msg::IfAlgorhmitimage::_image_type arg)
  {
    msg_.image = std::move(arg);
    return Init_IfAlgorhmitimage_robpos(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitimage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitimage>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitimage_image();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__BUILDER_HPP_
