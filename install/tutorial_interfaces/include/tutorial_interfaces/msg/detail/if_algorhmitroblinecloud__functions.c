// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `lasertrackoutcloud`
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__functions.h"
// Member `targetpointoutcloud`
#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__functions.h"

bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__init(tutorial_interfaces__msg__IfAlgorhmitroblinecloud * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(msg);
    return false;
  }
  // lasertrackoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__init(&msg->lasertrackoutcloud, 0)) {
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(msg);
    return false;
  }
  // targetpointoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__init(&msg->targetpointoutcloud, 0)) {
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(msg);
    return false;
  }
  // solderjoints
  return true;
}

void
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(tutorial_interfaces__msg__IfAlgorhmitroblinecloud * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // lasertrackoutcloud
  tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__fini(&msg->lasertrackoutcloud);
  // targetpointoutcloud
  tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__fini(&msg->targetpointoutcloud);
  // solderjoints
}

bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__are_equal(const tutorial_interfaces__msg__IfAlgorhmitroblinecloud * lhs, const tutorial_interfaces__msg__IfAlgorhmitroblinecloud * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // lasertrackoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__are_equal(
      &(lhs->lasertrackoutcloud), &(rhs->lasertrackoutcloud)))
  {
    return false;
  }
  // targetpointoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__are_equal(
      &(lhs->targetpointoutcloud), &(rhs->targetpointoutcloud)))
  {
    return false;
  }
  // solderjoints
  if (lhs->solderjoints != rhs->solderjoints) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__copy(
  const tutorial_interfaces__msg__IfAlgorhmitroblinecloud * input,
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // lasertrackoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__copy(
      &(input->lasertrackoutcloud), &(output->lasertrackoutcloud)))
  {
    return false;
  }
  // targetpointoutcloud
  if (!tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__copy(
      &(input->targetpointoutcloud), &(output->targetpointoutcloud)))
  {
    return false;
  }
  // solderjoints
  output->solderjoints = input->solderjoints;
  return true;
}

tutorial_interfaces__msg__IfAlgorhmitroblinecloud *
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__create()
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * msg = (tutorial_interfaces__msg__IfAlgorhmitroblinecloud *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitroblinecloud));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__IfAlgorhmitroblinecloud));
  bool success = tutorial_interfaces__msg__IfAlgorhmitroblinecloud__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__destroy(tutorial_interfaces__msg__IfAlgorhmitroblinecloud * msg)
{
  if (msg) {
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__init(tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * data = NULL;
  if (size) {
    data = (tutorial_interfaces__msg__IfAlgorhmitroblinecloud *)calloc(size, sizeof(tutorial_interfaces__msg__IfAlgorhmitroblinecloud));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__IfAlgorhmitroblinecloud__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__fini(tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__create(size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * array = (tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__destroy(tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * array)
{
  if (array) {
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__are_equal(const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * lhs, const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__copy(
  const tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * input,
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__IfAlgorhmitroblinecloud);
    tutorial_interfaces__msg__IfAlgorhmitroblinecloud * data =
      (tutorial_interfaces__msg__IfAlgorhmitroblinecloud *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__IfAlgorhmitroblinecloud__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
