// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitrobcloud_cloudline
{
public:
  Init_IfAlgorhmitrobcloud_cloudline()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitrobcloud cloudline(::tutorial_interfaces::msg::IfAlgorhmitrobcloud::_cloudline_type arg)
  {
    msg_.cloudline = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobcloud msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitrobcloud>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitrobcloud_cloudline();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__BUILDER_HPP_
