// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'robpos'
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.h"

// Struct defined in msg/IfAlgorhmitimage in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitimage
{
  sensor_msgs__msg__Image image;
  tutorial_interfaces__msg__IfAlgorhmitrobpos robpos;
} tutorial_interfaces__msg__IfAlgorhmitimage;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitimage.
typedef struct tutorial_interfaces__msg__IfAlgorhmitimage__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitimage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitimage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITIMAGE__STRUCT_H_
