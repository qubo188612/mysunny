// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmitrobpos & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: posx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posx: ";
    value_to_yaml(msg.posx, out);
    out << "\n";
  }

  // member: posy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posy: ";
    value_to_yaml(msg.posy, out);
    out << "\n";
  }

  // member: posz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posz: ";
    value_to_yaml(msg.posz, out);
    out << "\n";
  }

  // member: posrx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posrx: ";
    value_to_yaml(msg.posrx, out);
    out << "\n";
  }

  // member: posry
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posry: ";
    value_to_yaml(msg.posry, out);
    out << "\n";
  }

  // member: posrz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posrz: ";
    value_to_yaml(msg.posrz, out);
    out << "\n";
  }

  // member: posout1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posout1: ";
    value_to_yaml(msg.posout1, out);
    out << "\n";
  }

  // member: posout2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posout2: ";
    value_to_yaml(msg.posout2, out);
    out << "\n";
  }

  // member: posout3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posout3: ";
    value_to_yaml(msg.posout3, out);
    out << "\n";
  }

  // member: toolid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toolid: ";
    value_to_yaml(msg.toolid, out);
    out << "\n";
  }

  // member: tcpid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tcpid: ";
    value_to_yaml(msg.tcpid, out);
    out << "\n";
  }

  // member: usertcpid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usertcpid: ";
    value_to_yaml(msg.usertcpid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmitrobpos & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmitrobpos>()
{
  return "tutorial_interfaces::msg::IfAlgorhmitrobpos";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmitrobpos>()
{
  return "tutorial_interfaces/msg/IfAlgorhmitrobpos";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitrobpos>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitrobpos>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmitrobpos>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__TRAITS_HPP_
