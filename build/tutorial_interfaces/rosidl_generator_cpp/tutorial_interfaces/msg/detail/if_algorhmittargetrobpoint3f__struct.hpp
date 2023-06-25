// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetrobpoint3f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmittargetrobpoint3f_
{
  using Type = IfAlgorhmittargetrobpoint3f_<ContainerAllocator>;

  explicit IfAlgorhmittargetrobpoint3f_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->uy = 0.0f;
      this->vz = 0.0f;
      this->u = 0l;
      this->v = 0l;
      this->name = "";
    }
  }

  explicit IfAlgorhmittargetrobpoint3f_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->uy = 0.0f;
      this->vz = 0.0f;
      this->u = 0l;
      this->v = 0l;
      this->name = "";
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _uy_type =
    float;
  _uy_type uy;
  using _vz_type =
    float;
  _vz_type vz;
  using _u_type =
    int32_t;
  _u_type u;
  using _v_type =
    int32_t;
  _v_type v;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__uy(
    const float & _arg)
  {
    this->uy = _arg;
    return *this;
  }
  Type & set__vz(
    const float & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__u(
    const int32_t & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const int32_t & _arg)
  {
    this->v = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmittargetrobpoint3f_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->uy != other.uy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmittargetrobpoint3f_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmittargetrobpoint3f_

// alias to use template instance with default allocator
using IfAlgorhmittargetrobpoint3f =
  tutorial_interfaces::msg::IfAlgorhmittargetrobpoint3f_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETROBPOINT3F__STRUCT_HPP_
