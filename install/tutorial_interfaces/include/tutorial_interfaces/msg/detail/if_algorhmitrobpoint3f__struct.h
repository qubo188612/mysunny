// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpoint3f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOINT3F__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOINT3F__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/IfAlgorhmitrobpoint3f in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobpoint3f
{
  float x;
  float y;
  float z;
  float uy;
  float vz;
  int32_t u;
  int32_t v;
} tutorial_interfaces__msg__IfAlgorhmitrobpoint3f;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitrobpoint3f.
typedef struct tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitrobpoint3f * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITROBPOINT3F__STRUCT_H_
