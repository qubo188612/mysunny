// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__init(tutorial_interfaces__msg__IfAlgorhmitrobpos * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(msg);
    return false;
  }
  // posx
  // posy
  // posz
  // posrx
  // posry
  // posrz
  // posout1
  // posout2
  // posout3
  // toolid
  // tcpid
  // usertcpid
  return true;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(tutorial_interfaces__msg__IfAlgorhmitrobpos * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // posx
  // posy
  // posz
  // posrx
  // posry
  // posrz
  // posout1
  // posout2
  // posout3
  // toolid
  // tcpid
  // usertcpid
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__are_equal(const tutorial_interfaces__msg__IfAlgorhmitrobpos * lhs, const tutorial_interfaces__msg__IfAlgorhmitrobpos * rhs)
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
  // posx
  if (lhs->posx != rhs->posx) {
    return false;
  }
  // posy
  if (lhs->posy != rhs->posy) {
    return false;
  }
  // posz
  if (lhs->posz != rhs->posz) {
    return false;
  }
  // posrx
  if (lhs->posrx != rhs->posrx) {
    return false;
  }
  // posry
  if (lhs->posry != rhs->posry) {
    return false;
  }
  // posrz
  if (lhs->posrz != rhs->posrz) {
    return false;
  }
  // posout1
  if (lhs->posout1 != rhs->posout1) {
    return false;
  }
  // posout2
  if (lhs->posout2 != rhs->posout2) {
    return false;
  }
  // posout3
  if (lhs->posout3 != rhs->posout3) {
    return false;
  }
  // toolid
  if (lhs->toolid != rhs->toolid) {
    return false;
  }
  // tcpid
  if (lhs->tcpid != rhs->tcpid) {
    return false;
  }
  // usertcpid
  if (lhs->usertcpid != rhs->usertcpid) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__copy(
  const tutorial_interfaces__msg__IfAlgorhmitrobpos * input,
  tutorial_interfaces__msg__IfAlgorhmitrobpos * output)
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
  // posx
  output->posx = input->posx;
  // posy
  output->posy = input->posy;
  // posz
  output->posz = input->posz;
  // posrx
  output->posrx = input->posrx;
  // posry
  output->posry = input->posry;
  // posrz
  output->posrz = input->posrz;
  // posout1
  output->posout1 = input->posout1;
  // posout2
  output->posout2 = input->posout2;
  // posout3
  output->posout3 = input->posout3;
  // toolid
  output->toolid = input->toolid;
  // tcpid
  output->tcpid = input->tcpid;
  // usertcpid
  output->usertcpid = input->usertcpid;
  return true;
}

tutorial_interfaces__msg__IfAlgorhmitrobpos *
tutorial_interfaces__msg__IfAlgorhmitrobpos__create()
{
  tutorial_interfaces__msg__IfAlgorhmitrobpos * msg = (tutorial_interfaces__msg__IfAlgorhmitrobpos *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpos));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpos));
  bool success = tutorial_interfaces__msg__IfAlgorhmitrobpos__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobpos__destroy(tutorial_interfaces__msg__IfAlgorhmitrobpos * msg)
{
  if (msg) {
    tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__init(tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__msg__IfAlgorhmitrobpos * data = NULL;
  if (size) {
    data = (tutorial_interfaces__msg__IfAlgorhmitrobpos *)calloc(size, sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpos));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__IfAlgorhmitrobpos__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(&data[i - 1]);
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
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__fini(tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(&array->data[i]);
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

tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence *
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__create(size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * array = (tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__destroy(tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * array)
{
  if (array) {
    tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__are_equal(const tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * lhs, const tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__IfAlgorhmitrobpos__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence__copy(
  const tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * input,
  tutorial_interfaces__msg__IfAlgorhmitrobpos__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__IfAlgorhmitrobpos);
    tutorial_interfaces__msg__IfAlgorhmitrobpos * data =
      (tutorial_interfaces__msg__IfAlgorhmitrobpos *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__IfAlgorhmitrobpos__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__IfAlgorhmitrobpos__fini(&data[i]);
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
    if (!tutorial_interfaces__msg__IfAlgorhmitrobpos__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
