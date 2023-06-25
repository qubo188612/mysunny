// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__struct.hpp"
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

void IfAlgorhmitrobcloud_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tutorial_interfaces::msg::IfAlgorhmitrobcloud(_init);
}

void IfAlgorhmitrobcloud_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tutorial_interfaces::msg::IfAlgorhmitrobcloud *>(message_memory);
  typed_message->~IfAlgorhmitrobcloud();
}

size_t size_function__IfAlgorhmitrobcloud__cloudline(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IfAlgorhmitrobcloud__cloudline(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud> *>(untyped_member);
  return &member[index];
}

void * get_function__IfAlgorhmitrobcloud__cloudline(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud> *>(untyped_member);
  return &member[index];
}

void resize_function__IfAlgorhmitrobcloud__cloudline(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IfAlgorhmitrobcloud_message_member_array[1] = {
  {
    "cloudline",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitroblinecloud>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitrobcloud, cloudline),  // bytes offset in struct
    nullptr,  // default value
    size_function__IfAlgorhmitrobcloud__cloudline,  // size() function pointer
    get_const_function__IfAlgorhmitrobcloud__cloudline,  // get_const(index) function pointer
    get_function__IfAlgorhmitrobcloud__cloudline,  // get(index) function pointer
    resize_function__IfAlgorhmitrobcloud__cloudline  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IfAlgorhmitrobcloud_message_members = {
  "tutorial_interfaces::msg",  // message namespace
  "IfAlgorhmitrobcloud",  // message name
  1,  // number of fields
  sizeof(tutorial_interfaces::msg::IfAlgorhmitrobcloud),
  IfAlgorhmitrobcloud_message_member_array,  // message members
  IfAlgorhmitrobcloud_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitrobcloud_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IfAlgorhmitrobcloud_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IfAlgorhmitrobcloud_message_members,
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
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitrobcloud>()
{
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitrobcloud_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tutorial_interfaces, msg, IfAlgorhmitrobcloud)() {
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitrobcloud_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
