// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'cloudline'
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmitrobcloud & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cloudline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cloudline.size() == 0) {
      out << "cloudline: []\n";
    } else {
      out << "cloudline:\n";
      for (auto item : msg.cloudline) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmitrobcloud & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmitrobcloud>()
{
  return "tutorial_interfaces::msg::IfAlgorhmitrobcloud";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmitrobcloud>()
{
  return "tutorial_interfaces/msg/IfAlgorhmitrobcloud";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitrobcloud>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitrobcloud>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmitrobcloud>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__TRAITS_HPP_
