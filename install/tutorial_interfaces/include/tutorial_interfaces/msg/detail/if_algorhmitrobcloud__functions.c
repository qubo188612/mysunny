// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobcloud.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitrobcloud__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `cloudline`
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__functions.h"

bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__init(tutorial_interfaces__msg__IfAlgorhmitrobcloud * msg)
{
  if (!msg) {
    return false;
  }
  // cloudline
  if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__init(&msg->cloudline, 0)) {
    tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(tutorial_interfaces__msg__IfAlgorhmitrobcloud * msg)
{
  if (!msg) {
    return;
  }
  // cloudline
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__fini(&msg->cloudline);
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__are_equal(const tutorial_interfaces__msg__IfAlgorhmitrobcloud * lhs, const tutorial_interfaces__msg__IfAlgorhmitrobcloud * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cloudline
  if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__are_equal(
      &(lhs->cloudline), &(rhs->cloudline)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__copy(
  const tutorial_interfaces__msg__IfAlgorhmitrobcloud * input,
  tutorial_interfaces__msg__IfAlgorhmitrobcloud * output)
{
  if (!input || !output) {
    return false;
  }
  // cloudline
  if (!tutorial_interfaces__msg__IfAlgorhmitroblinecloud__Sequence__copy(
      &(input->cloudline), &(output->cloudline)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__msg__IfAlgorhmitrobcloud *
tutorial_interfaces__msg__IfAlgorhmitrobcloud__create()
{
  tutorial_interfaces__msg__IfAlgorhmitrobcloud * msg = (tutorial_interfaces__msg__IfAlgorhmitrobcloud *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud));
  bool success = tutorial_interfaces__msg__IfAlgorhmitrobcloud__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobcloud__destroy(tutorial_interfaces__msg__IfAlgorhmitrobcloud * msg)
{
  if (msg) {
    tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__init(tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__msg__IfAlgorhmitrobcloud * data = NULL;
  if (size) {
    data = (tutorial_interfaces__msg__IfAlgorhmitrobcloud *)calloc(size, sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__IfAlgorhmitrobcloud__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(&data[i - 1]);
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
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__fini(tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(&array->data[i]);
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

tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence *
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__create(size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * array = (tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__destroy(tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * array)
{
  if (array) {
    tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__are_equal(const tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * lhs, const tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__IfAlgorhmitrobcloud__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence__copy(
  const tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * input,
  tutorial_interfaces__msg__IfAlgorhmitrobcloud__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__IfAlgorhmitrobcloud);
    tutorial_interfaces__msg__IfAlgorhmitrobcloud * data =
      (tutorial_interfaces__msg__IfAlgorhmitrobcloud *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__IfAlgorhmitrobcloud__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__IfAlgorhmitrobcloud__fini(&data[i]);
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
    if (!tutorial_interfaces__msg__IfAlgorhmitrobcloud__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
