// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__struct.h"


// Include directives for member types
// Member `cloudline`
#include "tutorial_interfaces/msg/if_algorhmitroblinecloud.h"
// Member `cloudline`
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmitrobcloud__init(message_memory);
}

void IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(message_memory);
}

size_t IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitroblinecloud__cloudline(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitroblinecloud__cloudline(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitroblinecloud__cloudline(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitroblinecloud__cloudline(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_member_array[1] = {
  {
    "cloudline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitrobcloud, cloudline),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitroblinecloud__cloudline,  // size() function pointer
    IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitroblinecloud__cloudline,  // get_const(index) function pointer
    IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitroblinecloud__cloudline,  // get(index) function pointer
    IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitroblinecloud__cloudline  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmitrobcloud",  // message name
  1,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud),
  IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_member_array,  // message members
  IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_type_support_handle = {
  0,
  &IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitrobcloud)() {
  IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitroblinecloud)();
  if (!IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmitrobcloud__rosidl_typesupport_introspection_c__IfAlgorhmitrobcloud_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
