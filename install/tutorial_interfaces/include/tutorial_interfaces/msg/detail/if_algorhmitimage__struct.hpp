// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'robpos'
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitimage __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitimage __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitimage_
{
  using Type = IfAlgorhmitimage_<ContainerAllocator>;

  explicit IfAlgorhmitimage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init),
    robpos(_init)
  {
    (void)_init;
  }

  explicit IfAlgorhmitimage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init),
    robpos(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;
  using _robpos_type =
    tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>;
  _robpos_type robpos;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }
  Type & set__robpos(
    const tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> & _arg)
  {
    this->robpos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitimage
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitimage
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitimage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitimage_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    if (this->robpos != other.robpos) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitimage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitimage_

// alias to use template instance with default allocator
using IfAlgorhmitimage =
  tutorial_interfaces::msg::IfAlgorhmitimage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_HPP_
