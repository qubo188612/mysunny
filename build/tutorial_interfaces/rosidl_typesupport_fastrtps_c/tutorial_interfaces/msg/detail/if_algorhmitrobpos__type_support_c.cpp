// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__functions.h"
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


using _IfAlgorhmitrobpos__ros_msg_type = tutorial_interfaces__msg__IfAlgorhmitrobpos;

static bool _IfAlgorhmitrobpos__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IfAlgorhmitrobpos__ros_msg_type * ros_message = static_cast<const _IfAlgorhmitrobpos__ros_msg_type *>(untyped_ros_message);
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

  // Field name: posx
  {
    cdr << ros_message->posx;
  }

  // Field name: posy
  {
    cdr << ros_message->posy;
  }

  // Field name: posz
  {
    cdr << ros_message->posz;
  }

  // Field name: posrx
  {
    cdr << ros_message->posrx;
  }

  // Field name: posry
  {
    cdr << ros_message->posry;
  }

  // Field name: posrz
  {
    cdr << ros_message->posrz;
  }

  // Field name: posout1
  {
    cdr << ros_message->posout1;
  }

  // Field name: posout2
  {
    cdr << ros_message->posout2;
  }

  // Field name: posout3
  {
    cdr << ros_message->posout3;
  }

  // Field name: toolid
  {
    cdr << ros_message->toolid;
  }

  // Field name: tcpid
  {
    cdr << ros_message->tcpid;
  }

  // Field name: usertcpid
  {
    cdr << ros_message->usertcpid;
  }

  return true;
}

static bool _IfAlgorhmitrobpos__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IfAlgorhmitrobpos__ros_msg_type * ros_message = static_cast<_IfAlgorhmitrobpos__ros_msg_type *>(untyped_ros_message);
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

  // Field name: posx
  {
    cdr >> ros_message->posx;
  }

  // Field name: posy
  {
    cdr >> ros_message->posy;
  }

  // Field name: posz
  {
    cdr >> ros_message->posz;
  }

  // Field name: posrx
  {
    cdr >> ros_message->posrx;
  }

  // Field name: posry
  {
    cdr >> ros_message->posry;
  }

  // Field name: posrz
  {
    cdr >> ros_message->posrz;
  }

  // Field name: posout1
  {
    cdr >> ros_message->posout1;
  }

  // Field name: posout2
  {
    cdr >> ros_message->posout2;
  }

  // Field name: posout3
  {
    cdr >> ros_message->posout3;
  }

  // Field name: toolid
  {
    cdr >> ros_message->toolid;
  }

  // Field name: tcpid
  {
    cdr >> ros_message->tcpid;
  }

  // Field name: usertcpid
  {
    cdr >> ros_message->usertcpid;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpos(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IfAlgorhmitrobpos__ros_msg_type * ros_message = static_cast<const _IfAlgorhmitrobpos__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name posx
  {
    size_t item_size = sizeof(ros_message->posx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posy
  {
    size_t item_size = sizeof(ros_message->posy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posz
  {
    size_t item_size = sizeof(ros_message->posz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posrx
  {
    size_t item_size = sizeof(ros_message->posrx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posry
  {
    size_t item_size = sizeof(ros_message->posry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posrz
  {
    size_t item_size = sizeof(ros_message->posrz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posout1
  {
    size_t item_size = sizeof(ros_message->posout1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posout2
  {
    size_t item_size = sizeof(ros_message->posout2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name posout3
  {
    size_t item_size = sizeof(ros_message->posout3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toolid
  {
    size_t item_size = sizeof(ros_message->toolid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tcpid
  {
    size_t item_size = sizeof(ros_message->tcpid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name usertcpid
  {
    size_t item_size = sizeof(ros_message->usertcpid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _IfAlgorhmitrobpos__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpos(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tutorial_interfaces
size_t max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpos(
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
  // member: posx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posrx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posry
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posrz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posout1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posout2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: posout3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: toolid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tcpid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: usertcpid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _IfAlgorhmitrobpos__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tutorial_interfaces__msg__IfAlgorhmitrobpos(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IfAlgorhmitrobpos = {
  "tutorial_interfaces::msg",
  "IfAlgorhmitrobpos",
  _IfAlgorhmitrobpos__cdr_serialize,
  _IfAlgorhmitrobpos__cdr_deserialize,
  _IfAlgorhmitrobpos__get_serialized_size,
  _IfAlgorhmitrobpos__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmitrobpos__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IfAlgorhmitrobpos,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tutorial_interfaces, msg, IfAlgorhmitrobpos)() {
  return &_IfAlgorhmitrobpos__type_support;
}

#if defined(__cplusplus)
}
#endif
