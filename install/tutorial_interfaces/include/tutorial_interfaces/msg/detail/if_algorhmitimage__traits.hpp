// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitimage__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'robpos'
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmitimage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_yaml(msg.image, out, indentation + 2);
  }

  // member: robpos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robpos:\n";
    to_yaml(msg.robpos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmitimage & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmitimage>()
{
  return "tutorial_interfaces::msg::IfAlgorhmitimage";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmitimage>()
{
  return "tutorial_interfaces/msg/IfAlgorhmitimage";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitimage>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitrobpos>::value> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitimage>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitrobpos>::value> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmitimage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__TRAITS_HPP_
