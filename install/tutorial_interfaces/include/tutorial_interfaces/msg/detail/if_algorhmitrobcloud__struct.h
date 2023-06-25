// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cloudline'
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.h"

// Struct defined in msg/IfAlgorhmitrobcloud in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobcloud
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence cloudline;
} tutorial_interfaces__msg__IfAlgorhmitrobcloud;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitrobcloud.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitrobcloud * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBCLOUD__STRUCT_H_
