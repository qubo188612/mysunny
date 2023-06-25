// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__struct.hpp"

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
bool cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmitroblinecloud &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tutorial_interfaces::msg::IfAlgorhmitroblinecloud &);
size_t get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitroblinecloud &,
  size_t current_alignment);
size_t
max_serialized_size_IfAlgorhmitroblinecloud(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmitrobcloud & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: cloudline
  {
    size_t size = ros_message.cloudline.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.cloudline[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tutorial_interfaces::msg::IfAlgorhmitrobcloud & ros_message)
{
  // Member: cloudline
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.cloudline.resize(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.cloudline[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitrobcloud & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: cloudline
  {
    size_t array_size = ros_message.cloudline.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.cloudline[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
max_serialized_size_IfAlgorhmitrobcloud(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: cloudline
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_IfAlgorhmitroblinecloud(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _IfAlgorhmitrobcloud__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitrobcloud *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IfAlgorhmitrobcloud__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tutorial_interfaces::msg::IfAlgorhmitrobcloud *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IfAlgorhmitrobcloud__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitrobcloud *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IfAlgorhmitrobcloud__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_IfAlgorhmitrobcloud(full_bounded, 0);
}

static message_type_support_callbacks_t _IfAlgorhmitrobcloud__callbacks = {
  "tutorial_interfaces::msg",
  "IfAlgorhmitrobcloud",
  _IfAlgorhmitrobcloud__cdr_serialize,
  _IfAlgorhmitrobcloud__cdr_deserialize,
  _IfAlgorhmitrobcloud__get_serialized_size,
  _IfAlgorhmitrobcloud__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmitrobcloud__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IfAlgorhmitrobcloud__callbacks,
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
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitrobcloud>()
{
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitrobcloud__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tutorial_interfaces, msg, IfAlgorhmitrobcloud)() {
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitrobcloud__handle;
}

#ifdef __cplusplus
}
#endif
