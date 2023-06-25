// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'lasertrackoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__struct.hpp"
// Member 'targetpointoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitroblinecloud __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitroblinecloud __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitroblinecloud_
{
  using Type = IfAlgorhmitroblinecloud_<ContainerAllocator>;

  explicit IfAlgorhmitroblinecloud_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->solderjoints = false;
    }
  }

  explicit IfAlgorhmitroblinecloud_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->solderjoints = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _lasertrackoutcloud_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f_<ContainerAllocator>>>;
  _lasertrackoutcloud_type lasertrackoutcloud;
  using _targetpointoutcloud_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>>;
  _targetpointoutcloud_type targetpointoutcloud;
  using _solderjoints_type =
    bool;
  _solderjoints_type solderjoints;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__lasertrackoutcloud(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitrobpoint3f_<ContainerAllocator>>> & _arg)
  {
    this->lasertrackoutcloud = _arg;
    return *this;
  }
  Type & set__targetpointoutcloud(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>> & _arg)
  {
    this->targetpointoutcloud = _arg;
    return *this;
  }
  Type & set__solderjoints(
    const bool & _arg)
  {
    this->solderjoints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitroblinecloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitroblinecloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitroblinecloud_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->lasertrackoutcloud != other.lasertrackoutcloud) {
      return false;
    }
    if (this->targetpointoutcloud != other.targetpointoutcloud) {
      return false;
    }
    if (this->solderjoints != other.solderjoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitroblinecloud_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitroblinecloud_

// alias to use template instance with default allocator
using IfAlgorhmitroblinecloud =
  tutorial_interfaces::msg::IfAlgorhmitroblinecloud_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_HPP_
