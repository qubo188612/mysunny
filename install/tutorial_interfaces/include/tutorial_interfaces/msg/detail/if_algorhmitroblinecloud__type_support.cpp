// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.hpp"
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

void IfAlgorhmitroblinecloud_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tutorial_interfaces::msg::IfAlgorhmitroblinecloud(_init);
}

void IfAlgorhmitroblinecloud_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tutorial_interfaces::msg::IfAlgorhmitroblinecloud *>(message_memory);
  typed_message->~IfAlgorhmitroblinecloud();
}

size_t size_function__IfAlgorhmitroblinecloud__lasertrackoutcloud(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IfAlgorhmitroblinecloud__lasertrackoutcloud(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f> *>(untyped_member);
  return &member[index];
}

void * get_function__IfAlgorhmitroblinecloud__lasertrackoutcloud(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f> *>(untyped_member);
  return &member[index];
}

void resize_function__IfAlgorhmitroblinecloud__lasertrackoutcloud(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f> *>(untyped_member);
  member->resize(size);
}

size_t size_function__IfAlgorhmitroblinecloud__targetpointoutcloud(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IfAlgorhmitroblinecloud__targetpointoutcloud(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f> *>(untyped_member);
  return &member[index];
}

void * get_function__IfAlgorhmitroblinecloud__targetpointoutcloud(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f> *>(untyped_member);
  return &member[index];
}

void resize_function__IfAlgorhmitroblinecloud__targetpointoutcloud(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IfAlgorhmitroblinecloud_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitroblinecloud, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lasertrackoutcloud",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitroblinecloud, lasertrackoutcloud),  // bytes offset in struct
    nullptr,  // default value
    size_function__IfAlgorhmitroblinecloud__lasertrackoutcloud,  // size() function pointer
    get_const_function__IfAlgorhmitroblinecloud__lasertrackoutcloud,  // get_const(index) function pointer
    get_function__IfAlgorhmitroblinecloud__lasertrackoutcloud,  // get(index) function pointer
    resize_function__IfAlgorhmitroblinecloud__lasertrackoutcloud  // resize(index) function pointer
  },
  {
    "targetpointoutcloud",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitroblinecloud, targetpointoutcloud),  // bytes offset in struct
    nullptr,  // default value
    size_function__IfAlgorhmitroblinecloud__targetpointoutcloud,  // size() function pointer
    get_const_function__IfAlgorhmitroblinecloud__targetpointoutcloud,  // get_const(index) function pointer
    get_function__IfAlgorhmitroblinecloud__targetpointoutcloud,  // get(index) function pointer
    resize_function__IfAlgorhmitroblinecloud__targetpointoutcloud  // resize(index) function pointer
  },
  {
    "solderjoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitroblinecloud, solderjoints),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IfAlgorhmitroblinecloud_message_members = {
  "tutorial_interfaces::msg",  // message namespace
  "IfAlgorhmitroblinecloud",  // message name
  4,  // number of fields
  sizeof(tutorial_interfaces::msg::IfAlgorhmitroblinecloud),
  IfAlgorhmitroblinecloud_message_member_array,  // message members
  IfAlgorhmitroblinecloud_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitroblinecloud_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IfAlgorhmitroblinecloud_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IfAlgorhmitroblinecloud_message_members,
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
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitroblinecloud>()
{
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitroblinecloud_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tutorial_interfaces, msg, IfAlgorhmitroblinecloud)() {
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitroblinecloud_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
