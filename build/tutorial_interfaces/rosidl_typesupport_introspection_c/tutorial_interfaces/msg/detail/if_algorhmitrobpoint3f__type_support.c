// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpoint3f.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__init(message_memory);
}

void IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_member_array[7] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, uy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, vz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "u",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, u),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f, v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmitrobpoint3f",  // message name
  7,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpoint3f),
  IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_member_array,  // message members
  IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_type_support_handle = {
  0,
  &IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitrobpoint3f)() {
  if (!IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmitrobpoint3f__rosidl_typesupport_introspection_c__IfAlgorhmitrobpoint3f_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
