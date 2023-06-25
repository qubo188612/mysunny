// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tutorial_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IfAlgorhmitimage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tutorial_interfaces::msg::IfAlgorhmitimage(_init);
}

void IfAlgorhmitimage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tutorial_interfaces::msg::IfAlgorhmitimage *>(message_memory);
  typed_message->~IfAlgorhmitimage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IfAlgorhmitimage_message_member_array[2] = {
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitimage, image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "robpos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitrobpos>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitimage, robpos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IfAlgorhmitimage_message_members = {
  "tutorial_interfaces::msg",  // message namespace
  "IfAlgorhmitimage",  // message name
  2,  // number of fields
  sizeof(tutorial_interfaces::msg::IfAlgorhmitimage),
  IfAlgorhmitimage_message_member_array,  // message members
  IfAlgorhmitimage_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitimage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IfAlgorhmitimage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IfAlgorhmitimage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tutorial_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitimage>()
{
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitimage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tutorial_interfaces, msg, IfAlgorhmitimage)() {
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitimage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
