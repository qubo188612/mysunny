// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'cloudline'
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobcloud __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobcloud __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitrobcloud_
{
  using Type = IfAlgorhmitrobcloud_<ContainerAllocator>;

  explicit IfAlgorhmitrobcloud_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit IfAlgorhmitrobcloud_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _cloudline_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>>;
  _cloudline_type cloudline;

  // setters for named parameter idiom
  Type & set__cloudline(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>> & _arg)
  {
    this->cloudline = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobcloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobcloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobcloud_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitrobcloud_ & other) const
  {
    if (this->cloudline != other.cloudline) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitrobcloud_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitrobcloud_

// alias to use template instance with default allocator
using IfAlgorhmitrobcloud =
  tutorial_interfaces::msg::IfAlgorhmitrobcloud_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_HPP_
