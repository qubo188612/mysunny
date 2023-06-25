// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpoint3f.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace tutorial_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmitrobpoint3f & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x
  cdr << ros_message.x;
  // Member: y
  cdr << ros_message.y;
  // Member: z
  cdr << ros_message.z;
  // Member: uy
  cdr << ros_message.uy;
  // Member: vz
  cdr << ros_message.vz;
  // Member: u
  cdr << ros_message.u;
  // Member: v
  cdr << ros_message.v;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tutorial_interfaces::msg::IfAlgorhmitrobpoint3f & ros_message)
{
  // Member: x
  cdr >> ros_message.x;

  // Member: y
  cdr >> ros_message.y;

  // Member: z
  cdr >> ros_message.z;

  // Member: uy
  cdr >> ros_message.uy;

  // Member: vz
  cdr >> ros_message.vz;

  // Member: u
  cdr >> ros_message.u;

  // Member: v
  cdr >> ros_message.v;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitrobpoint3f & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: z
  {
    size_t item_size = sizeof(ros_message.z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: uy
  {
    size_t item_size = sizeof(ros_message.uy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vz
  {
    size_t item_size = sizeof(ros_message.vz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: u
  {
    size_t item_size = sizeof(ros_message.u);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v
  {
    size_t item_size = sizeof(ros_message.v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
max_serialized_size_IfAlgorhmitrobpoint3f(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: uy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: u
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: v
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _IfAlgorhmitrobpoint3f__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitrobpoint3f *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IfAlgorhmitrobpoint3f__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IfAlgorhmitrobpoint3f__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitrobpoint3f *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IfAlgorhmitrobpoint3f__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_IfAlgorhmitrobpoint3f(full_bounded, 0);
}

static message_type_support_callbacks_t _IfAlgorhmitrobpoint3f__callbacks = {
  "tutorial_interfaces::msg",
  "IfAlgorhmitrobpoint3f",
  _IfAlgorhmitrobpoint3f__cdr_serialize,
  _IfAlgorhmitrobpoint3f__cdr_deserialize,
  _IfAlgorhmitrobpoint3f__get_serialized_size,
  _IfAlgorhmitrobpoint3f__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmitrobpoint3f__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IfAlgorhmitrobpoint3f__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tutorial_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f>()
{
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitrobpoint3f__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tutorial_interfaces, msg, IfAlgorhmitrobpoint3f)() {
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitrobpoint3f__handle;
}

#ifdef __cplusplus
}
#endif
