// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetrobpoint3f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmittargetrobpoint3f_name
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_name(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f name(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_v
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_v(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_name v(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_v_type arg)
  {
    msg_.v = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_name(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_u
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_u(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_v u(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_v(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_vz
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_vz(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_u vz(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_u(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_uy
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_uy(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_vz uy(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_uy_type arg)
  {
    msg_.uy = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_vz(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_z
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_z(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_uy z(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_uy(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_y
{
public:
  explicit Init_IfAlgorhmittargetrobpoint3f_y(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetrobpoint3f_z y(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_z(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

class Init_IfAlgorhmittargetrobpoint3f_x
{
public:
  Init_IfAlgorhmittargetrobpoint3f_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmittargetrobpoint3f_y x(::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IfAlgorhmittargetrobpoint3f_y(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmittargetrobpoint3f_x();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__BUILDER_HPP_
