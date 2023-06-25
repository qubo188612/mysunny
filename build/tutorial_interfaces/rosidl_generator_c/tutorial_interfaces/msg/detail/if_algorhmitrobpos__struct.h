// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/IfAlgorhmitrobpos in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobpos
{
  std_msgs__msg__Header header;
  float posx;
  float posy;
  float posz;
  float posrx;
  float posry;
  float posrz;
  float posout1;
  float posout2;
  float posout3;
  int32_t toolid;
  int32_t tcpid;
  int32_t usertcpid;
} tutorial_interfaces__msg__IfAlgorhmitrobpos;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitrobpos.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitrobpos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOS__STRUCT_H_
