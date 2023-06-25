// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_H_

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
// Member 'lasertrackoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__struct.h"
// Member 'targetpointoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__struct.h"

// Struct defined in msg/IfAlgorhmitroblinecloud in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitroblinecloud
{
  std_msgs__msg__Header header;
  tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence lasertrackoutcloud;
  tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence targetpointoutcloud;
  bool solderjoints;
} tutorial_interfaces__msg__IfAlgorhmitroblinecloud;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitroblinecloud.
typedef struct tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBLINECLOUD__STRUCT_H_
