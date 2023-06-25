// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__functions.h"  // lasertrackoutcloud
#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__functions.h"  // targetpointoutcloud

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpoint3f(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpoint3f(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitrobpoint3f)();
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetrobpoint3f)();


using _IfAlgorhmitroblinecloud__ros_msg_type = tutorial_interfaces__msg__IfAlgorhmitroblinecloud;

static bool _IfAlgorhmitroblinecloud__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IfAlgorhmitroblinecloud__ros_msg_type * ros_message = static_cast<const _IfAlgorhmitroblinecloud__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: lasertrackoutcloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitrobpoint3f
      )()->data);
    size_t size = ros_message->lasertrackoutcloud.size;
    auto array_ptr = ros_message->lasertrackoutcloud.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: targetpointoutcloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetrobpoint3f
      )()->data);
    size_t size = ros_message->targetpointoutcloud.size;
    auto array_ptr = ros_message->targetpointoutcloud.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: solderjoints
  {
    cdr << (ros_message->solderjoints ? true : false);
  }

  return true;
}

static bool _IfAlgorhmitroblinecloud__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IfAlgorhmitroblinecloud__ros_msg_type * ros_message = static_cast<_IfAlgorhmitroblinecloud__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: lasertrackoutcloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitrobpoint3f
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->lasertrackoutcloud.data) {
      tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__fini(&ros_message->lasertrackoutcloud);
    }
    if (!tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__init(&ros_message->lasertrackoutcloud, size)) {
      fprintf(stderr, "failed to create array for field 'lasertrackoutcloud'");
      return false;
    }
    auto array_ptr = ros_message->lasertrackoutcloud.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: targetpointoutcloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetrobpoint3f
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->targetpointoutcloud.data) {
      tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__fini(&ros_message->targetpointoutcloud);
    }
    if (!tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__init(&ros_message->targetpointoutcloud, size)) {
      fprintf(stderr, "failed to create array for field 'targetpointoutcloud'");
      return false;
    }
    auto array_ptr = ros_message->targetpointoutcloud.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: solderjoints
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->solderjoints = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitroblinecloud(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IfAlgorhmitroblinecloud__ros_msg_type * ros_message = static_cast<const _IfAlgorhmitroblinecloud__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name lasertrackoutcloud
  {
    size_t array_size = ros_message->lasertrackoutcloud.size;
    auto array_ptr = ros_message->lasertrackoutcloud.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpoint3f(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name targetpointoutcloud
  {
    size_t array_size = ros_message->targetpointoutcloud.size;
    auto array_ptr = ros_message->targetpointoutcloud.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name solderjoints
  {
    size_t item_size = sizeof(ros_message->solderjoints);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _IfAlgorhmitroblinecloud__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitroblinecloud(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitroblinecloud(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: lasertrackoutcloud
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpoint3f(
        full_bounded, current_alignment);
    }
  }
  // member: targetpointoutcloud
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f(
        full_bounded, current_alignment);
    }
  }
  // member: solderjoints
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _IfAlgorhmitroblinecloud__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitroblinecloud(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IfAlgorhmitroblinecloud = {
  "tutorial_interfaces::msg",
  "IfAlgorhmitroblinecloud",
  _IfAlgorhmitroblinecloud__cdr_serialize,
  _IfAlgorhmitroblinecloud__cdr_deserialize,
  _IfAlgorhmitroblinecloud__get_serialized_size,
  _IfAlgorhmitroblinecloud__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmitroblinecloud__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IfAlgorhmitroblinecloud,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitroblinecloud)() {
  return &_IfAlgorhmitroblinecloud__type_support;
}

#if defined(__cplusplus)
}
#endif
