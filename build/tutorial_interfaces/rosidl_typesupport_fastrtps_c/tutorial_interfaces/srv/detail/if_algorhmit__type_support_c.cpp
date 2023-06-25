// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/srv/detail/if_algorhmit__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"
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

#include "sensor_msgs/msg/detail/image__functions.h"  // imagein

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _IfAlgorhmit_Request__ros_msg_type = tutorial_interfaces__srv__IfAlgorhmit_Request;

static bool _IfAlgorhmit_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IfAlgorhmit_Request__ros_msg_type * ros_message = static_cast<const _IfAlgorhmit_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: imagein
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->imagein, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _IfAlgorhmit_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IfAlgorhmit_Request__ros_msg_type * ros_message = static_cast<_IfAlgorhmit_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: imagein
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->imagein))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t get_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IfAlgorhmit_Request__ros_msg_type * ros_message = static_cast<const _IfAlgorhmit_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name imagein

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->imagein), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _IfAlgorhmit_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t max_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: imagein
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _IfAlgorhmit_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IfAlgorhmit_Request = {
  "tutorial_interfaces::srv",
  "IfAlgorhmit_Request",
  _IfAlgorhmit_Request__cdr_serialize,
  _IfAlgorhmit_Request__cdr_deserialize,
  _IfAlgorhmit_Request__get_serialized_size,
  _IfAlgorhmit_Request__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmit_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IfAlgorhmit_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, srv, IfAlgorhmit_Request)() {
  return &_IfAlgorhmit_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "tutorial_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "sensor_msgs/msg/detail/image__functions.h"  // imageout
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__functions.h"  // lasertrackout
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__functions.h"  // targetpointout

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tutorial_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitpoint2f(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitpoint2f(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitpoint2f)();
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetpoint2f(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetpoint2f(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f)();


using _IfAlgorhmit_Response__ros_msg_type = tutorial_interfaces__srv__IfAlgorhmit_Response;

static bool _IfAlgorhmit_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IfAlgorhmit_Response__ros_msg_type * ros_message = static_cast<const _IfAlgorhmit_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    cdr << (ros_message->result ? true : false);
  }

  // Field name: imageout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->imageout, cdr))
    {
      return false;
    }
  }

  // Field name: targetpointout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f
      )()->data);
    size_t size = ros_message->targetpointout.size;
    auto array_ptr = ros_message->targetpointout.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: lasertrackout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitpoint2f
      )()->data);
    size_t size = ros_message->lasertrackout.size;
    auto array_ptr = ros_message->lasertrackout.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _IfAlgorhmit_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IfAlgorhmit_Response__ros_msg_type * ros_message = static_cast<_IfAlgorhmit_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->result = tmp ? true : false;
  }

  // Field name: imageout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->imageout))
    {
      return false;
    }
  }

  // Field name: targetpointout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->targetpointout.data) {
      tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__fini(&ros_message->targetpointout);
    }
    if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__init(&ros_message->targetpointout, size)) {
      fprintf(stderr, "failed to create array for field 'targetpointout'");
      return false;
    }
    auto array_ptr = ros_message->targetpointout.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: lasertrackout
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitpoint2f
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->lasertrackout.data) {
      tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__fini(&ros_message->lasertrackout);
    }
    if (!tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__init(&ros_message->lasertrackout, size)) {
      fprintf(stderr, "failed to create array for field 'lasertrackout'");
      return false;
    }
    auto array_ptr = ros_message->lasertrackout.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t get_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IfAlgorhmit_Response__ros_msg_type * ros_message = static_cast<const _IfAlgorhmit_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name imageout

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->imageout), current_alignment);
  // field.name targetpointout
  {
    size_t array_size = ros_message->targetpointout.size;
    auto array_ptr = ros_message->targetpointout.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetpoint2f(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name lasertrackout
  {
    size_t array_size = ros_message->lasertrackout.size;
    auto array_ptr = ros_message->lasertrackout.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitpoint2f(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _IfAlgorhmit_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t max_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: result
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: imageout
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: targetpointout
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tutorial_interfaces__msg__IfAlgorhmittargetpoint2f(
        full_bounded, current_alignment);
    }
  }
  // member: lasertrackout
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitpoint2f(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _IfAlgorhmit_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tutorial_interfaces__srv__IfAlgorhmit_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IfAlgorhmit_Response = {
  "tutorial_interfaces::srv",
  "IfAlgorhmit_Response",
  _IfAlgorhmit_Response__cdr_serialize,
  _IfAlgorhmit_Response__cdr_deserialize,
  _IfAlgorhmit_Response__get_serialized_size,
  _IfAlgorhmit_Response__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmit_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IfAlgorhmit_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, srv, IfAlgorhmit_Response)() {
  return &_IfAlgorhmit_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "tutorial_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tutorial_interfaces/srv/if_algorhmit.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t IfAlgorhmit__callbacks = {
  "tutorial_interfaces::srv",
  "IfAlgorhmit",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, srv, IfAlgorhmit_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, srv, IfAlgorhmit_Response)(),
};

static rosidl_service_type_support_t IfAlgorhmit__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &IfAlgorhmit__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, srv, IfAlgorhmit)() {
  return &IfAlgorhmit__handle;
}

#if defined(__cplusplus)
}
#endif
