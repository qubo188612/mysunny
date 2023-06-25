// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace tutorial_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmitpoint4f &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tutorial_interfaces::msg::IfAlgorhmitpoint4f &);
size_t get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitpoint4f &,
  size_t current_alignment);
size_t
max_serialized_size_IfAlgorhmitpoint4f(
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
bool cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmittargetpoint4f &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tutorial_interfaces::msg::IfAlgorhmittargetpoint4f &);
size_t get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmittargetpoint4f &,
  size_t current_alignment);
size_t
max_serialized_size_IfAlgorhmittargetpoint4f(
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
bool cdr_serialize(
  const tutorial_interfaces::msg::IfAlgorhmitrobpos &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  tutorial_interfaces::msg::IfAlgorhmitrobpos &);
size_t get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitrobpos &,
  size_t current_alignment);
size_t
max_serialized_size_IfAlgorhmitrobpos(
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
  const tutorial_interfaces::msg::IfAlgorhmitcloud & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: lasertrackoutcloud
  {
    size_t size = ros_message.lasertrackoutcloud.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.lasertrackoutcloud[i],
        cdr);
    }
  }
  // Member: targetpointoutcloud
  {
    size_t size = ros_message.targetpointoutcloud.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.targetpointoutcloud[i],
        cdr);
    }
  }
  // Member: robpos
  tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.robpos,
    cdr);
  // Member: solderjoints
  cdr << (ros_message.solderjoints ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tutorial_interfaces::msg::IfAlgorhmitcloud & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: lasertrackoutcloud
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.lasertrackoutcloud.resize(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.lasertrackoutcloud[i]);
    }
  }

  // Member: targetpointoutcloud
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.targetpointoutcloud.resize(size);
    for (size_t i = 0; i < size; i++) {
      tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.targetpointoutcloud[i]);
    }
  }

  // Member: robpos
  tutorial_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.robpos);

  // Member: solderjoints
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.solderjoints = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
get_serialized_size(
  const tutorial_interfaces::msg::IfAlgorhmitcloud & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: lasertrackoutcloud
  {
    size_t array_size = ros_message.lasertrackoutcloud.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.lasertrackoutcloud[index], current_alignment);
    }
  }
  // Member: targetpointoutcloud
  {
    size_t array_size = ros_message.targetpointoutcloud.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.targetpointoutcloud[index], current_alignment);
    }
  }
  // Member: robpos

  current_alignment +=
    tutorial_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.robpos, current_alignment);
  // Member: solderjoints
  {
    size_t item_size = sizeof(ros_message.solderjoints);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tutorial_interfaces
max_serialized_size_IfAlgorhmitcloud(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: lasertrackoutcloud
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_IfAlgorhmitpoint4f(
        full_bounded, current_alignment);
    }
  }

  // Member: targetpointoutcloud
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_IfAlgorhmittargetpoint4f(
        full_bounded, current_alignment);
    }
  }

  // Member: robpos
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        tutorial_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_IfAlgorhmitrobpos(
        full_bounded, current_alignment);
    }
  }

  // Member: solderjoints
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _IfAlgorhmitcloud__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitcloud *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IfAlgorhmitcloud__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tutorial_interfaces::msg::IfAlgorhmitcloud *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IfAlgorhmitcloud__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tutorial_interfaces::msg::IfAlgorhmitcloud *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IfAlgorhmitcloud__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_IfAlgorhmitcloud(full_bounded, 0);
}

static message_type_support_callbacks_t _IfAlgorhmitcloud__callbacks = {
  "tutorial_interfaces::msg",
  "IfAlgorhmitcloud",
  _IfAlgorhmitcloud__cdr_serialize,
  _IfAlgorhmitcloud__cdr_deserialize,
  _IfAlgorhmitcloud__get_serialized_size,
  _IfAlgorhmitcloud__max_serialized_size
};

static rosidl_message_type_support_t _IfAlgorhmitcloud__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IfAlgorhmitcloud__callbacks,
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
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitcloud>()
{
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitcloud__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tutorial_interfaces, msg, IfAlgorhmitcloud)() {
  return &tutorial_interfaces::msg::typesupport_fastrtps_cpp::_IfAlgorhmitcloud__handle;
}

#ifdef __cplusplus
}
#endif
