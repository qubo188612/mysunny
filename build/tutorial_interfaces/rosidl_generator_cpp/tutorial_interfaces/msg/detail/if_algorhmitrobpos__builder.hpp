// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitrobpos_usertcpid
{
public:
  explicit Init_IfAlgorhmitrobpos_usertcpid(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos usertcpid(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_usertcpid_type arg)
  {
    msg_.usertcpid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_tcpid
{
public:
  explicit Init_IfAlgorhmitrobpos_tcpid(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_usertcpid tcpid(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_tcpid_type arg)
  {
    msg_.tcpid = std::move(arg);
    return Init_IfAlgorhmitrobpos_usertcpid(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_toolid
{
public:
  explicit Init_IfAlgorhmitrobpos_toolid(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_tcpid toolid(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_toolid_type arg)
  {
    msg_.toolid = std::move(arg);
    return Init_IfAlgorhmitrobpos_tcpid(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posout3
{
public:
  explicit Init_IfAlgorhmitrobpos_posout3(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_toolid posout3(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posout3_type arg)
  {
    msg_.posout3 = std::move(arg);
    return Init_IfAlgorhmitrobpos_toolid(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posout2
{
public:
  explicit Init_IfAlgorhmitrobpos_posout2(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posout3 posout2(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posout2_type arg)
  {
    msg_.posout2 = std::move(arg);
    return Init_IfAlgorhmitrobpos_posout3(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posout1
{
public:
  explicit Init_IfAlgorhmitrobpos_posout1(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posout2 posout1(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posout1_type arg)
  {
    msg_.posout1 = std::move(arg);
    return Init_IfAlgorhmitrobpos_posout2(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posrz
{
public:
  explicit Init_IfAlgorhmitrobpos_posrz(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posout1 posrz(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posrz_type arg)
  {
    msg_.posrz = std::move(arg);
    return Init_IfAlgorhmitrobpos_posout1(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posry
{
public:
  explicit Init_IfAlgorhmitrobpos_posry(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posrz posry(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posry_type arg)
  {
    msg_.posry = std::move(arg);
    return Init_IfAlgorhmitrobpos_posrz(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posrx
{
public:
  explicit Init_IfAlgorhmitrobpos_posrx(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posry posrx(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posrx_type arg)
  {
    msg_.posrx = std::move(arg);
    return Init_IfAlgorhmitrobpos_posry(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posz
{
public:
  explicit Init_IfAlgorhmitrobpos_posz(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posrx posz(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posz_type arg)
  {
    msg_.posz = std::move(arg);
    return Init_IfAlgorhmitrobpos_posrx(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posy
{
public:
  explicit Init_IfAlgorhmitrobpos_posy(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posz posy(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posy_type arg)
  {
    msg_.posy = std::move(arg);
    return Init_IfAlgorhmitrobpos_posz(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_posx
{
public:
  explicit Init_IfAlgorhmitrobpos_posx(::tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitrobpos_posy posx(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_posx_type arg)
  {
    msg_.posx = std::move(arg);
    return Init_IfAlgorhmitrobpos_posy(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

class Init_IfAlgorhmitrobpos_header
{
public:
  Init_IfAlgorhmitrobpos_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitrobpos_posx header(::tutorial_interfaces::msg::IfAlgorhmitrobpos::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IfAlgorhmitrobpos_posx(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitrobpos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitrobpos>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitrobpos_header();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__BUILDER_HPP_
