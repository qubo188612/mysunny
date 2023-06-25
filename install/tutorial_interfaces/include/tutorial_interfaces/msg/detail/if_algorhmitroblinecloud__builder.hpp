// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitroblinecloud_solderjoints
{
public:
  explicit Init_IfAlgorhmitroblinecloud_solderjoints(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitroblinecloud solderjoints(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud::_solderjoints_type arg)
  {
    msg_.solderjoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitroblinecloud msg_;
};

class Init_IfAlgorhmitroblinecloud_targetpointoutcloud
{
public:
  explicit Init_IfAlgorhmitroblinecloud_targetpointoutcloud(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitroblinecloud_solderjoints targetpointoutcloud(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud::_targetpointoutcloud_type arg)
  {
    msg_.targetpointoutcloud = std::move(arg);
    return Init_IfAlgorhmitroblinecloud_solderjoints(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitroblinecloud msg_;
};

class Init_IfAlgorhmitroblinecloud_lasertrackoutcloud
{
public:
  explicit Init_IfAlgorhmitroblinecloud_lasertrackoutcloud(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitroblinecloud_targetpointoutcloud lasertrackoutcloud(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud::_lasertrackoutcloud_type arg)
  {
    msg_.lasertrackoutcloud = std::move(arg);
    return Init_IfAlgorhmitroblinecloud_targetpointoutcloud(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitroblinecloud msg_;
};

class Init_IfAlgorhmitroblinecloud_header
{
public:
  Init_IfAlgorhmitroblinecloud_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitroblinecloud_lasertrackoutcloud header(::tutorial_interfaces::msg::IfAlgorhmitroblinecloud::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IfAlgorhmitroblinecloud_lasertrackoutcloud(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitroblinecloud msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitroblinecloud>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitroblinecloud_header();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__BUILDER_HPP_
