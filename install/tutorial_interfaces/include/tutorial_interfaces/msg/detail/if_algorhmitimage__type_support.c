// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `robpos`
#include "tutorial_interfaces/msg/if_algorhmitrobpos.h"
// Member `robpos`
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmitimage__init(message_memory);
}

void IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmitimage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_member_array[2] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitimage, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robpos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitimage, robpos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmitimage",  // message name
  2,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmitimage),
  IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_member_array,  // message members
  IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_type_support_handle = {
  0,
  &IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitimage)() {
  IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitrobpos)();
  if (!IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmitimage__rosidl_typesupport_introspection_c__IfAlgorhmitimage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
