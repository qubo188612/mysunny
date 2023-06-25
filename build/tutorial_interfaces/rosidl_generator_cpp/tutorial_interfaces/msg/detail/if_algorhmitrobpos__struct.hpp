// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobpos __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobpos __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitrobpos_
{
  using Type = IfAlgorhmitrobpos_<ContainerAllocator>;

  explicit IfAlgorhmitrobpos_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->posx = 0.0f;
      this->posy = 0.0f;
      this->posz = 0.0f;
      this->posrx = 0.0f;
      this->posry = 0.0f;
      this->posrz = 0.0f;
      this->posout1 = 0.0f;
      this->posout2 = 0.0f;
      this->posout3 = 0.0f;
      this->toolid = 0l;
      this->tcpid = 0l;
      this->usertcpid = 0l;
    }
  }

  explicit IfAlgorhmitrobpos_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->posx = 0.0f;
      this->posy = 0.0f;
      this->posz = 0.0f;
      this->posrx = 0.0f;
      this->posry = 0.0f;
      this->posrz = 0.0f;
      this->posout1 = 0.0f;
      this->posout2 = 0.0f;
      this->posout3 = 0.0f;
      this->toolid = 0l;
      this->tcpid = 0l;
      this->usertcpid = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _posx_type =
    float;
  _posx_type posx;
  using _posy_type =
    float;
  _posy_type posy;
  using _posz_type =
    float;
  _posz_type posz;
  using _posrx_type =
    float;
  _posrx_type posrx;
  using _posry_type =
    float;
  _posry_type posry;
  using _posrz_type =
    float;
  _posrz_type posrz;
  using _posout1_type =
    float;
  _posout1_type posout1;
  using _posout2_type =
    float;
  _posout2_type posout2;
  using _posout3_type =
    float;
  _posout3_type posout3;
  using _toolid_type =
    int32_t;
  _toolid_type toolid;
  using _tcpid_type =
    int32_t;
  _tcpid_type tcpid;
  using _usertcpid_type =
    int32_t;
  _usertcpid_type usertcpid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__posx(
    const float & _arg)
  {
    this->posx = _arg;
    return *this;
  }
  Type & set__posy(
    const float & _arg)
  {
    this->posy = _arg;
    return *this;
  }
  Type & set__posz(
    const float & _arg)
  {
    this->posz = _arg;
    return *this;
  }
  Type & set__posrx(
    const float & _arg)
  {
    this->posrx = _arg;
    return *this;
  }
  Type & set__posry(
    const float & _arg)
  {
    this->posry = _arg;
    return *this;
  }
  Type & set__posrz(
    const float & _arg)
  {
    this->posrz = _arg;
    return *this;
  }
  Type & set__posout1(
    const float & _arg)
  {
    this->posout1 = _arg;
    return *this;
  }
  Type & set__posout2(
    const float & _arg)
  {
    this->posout2 = _arg;
    return *this;
  }
  Type & set__posout3(
    const float & _arg)
  {
    this->posout3 = _arg;
    return *this;
  }
  Type & set__toolid(
    const int32_t & _arg)
  {
    this->toolid = _arg;
    return *this;
  }
  Type & set__tcpid(
    const int32_t & _arg)
  {
    this->tcpid = _arg;
    return *this;
  }
  Type & set__usertcpid(
    const int32_t & _arg)
  {
    this->usertcpid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobpos
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitrobpos
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitrobpos_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitrobpos_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->posx != other.posx) {
      return false;
    }
    if (this->posy != other.posy) {
      return false;
    }
    if (this->posz != other.posz) {
      return false;
    }
    if (this->posrx != other.posrx) {
      return false;
    }
    if (this->posry != other.posry) {
      return false;
    }
    if (this->posrz != other.posrz) {
      return false;
    }
    if (this->posout1 != other.posout1) {
      return false;
    }
    if (this->posout2 != other.posout2) {
      return false;
    }
    if (this->posout3 != other.posout3) {
      return false;
    }
    if (this->toolid != other.toolid) {
      return false;
    }
    if (this->tcpid != other.tcpid) {
      return false;
    }
    if (this->usertcpid != other.usertcpid) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitrobpos_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitrobpos_

// alias to use template instance with default allocator
using IfAlgorhmitrobpos =
  tutorial_interfaces::msg::IfAlgorhmitrobpos_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_HPP_
