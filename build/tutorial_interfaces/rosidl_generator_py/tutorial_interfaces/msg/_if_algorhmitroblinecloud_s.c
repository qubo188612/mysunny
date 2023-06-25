// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitroblinecloud.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__struct.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitroblinecloud__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpoint3f__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmittargetrobpoint3f__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool tutorial_interfaces__msg__if_algorhmitrobpoint3f__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tutorial_interfaces__msg__if_algorhmitrobpoint3f__convert_to_py(void * raw_ros_message);
bool tutorial_interfaces__msg__if_algorhmittargetrobpoint3f__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tutorial_interfaces__msg__if_algorhmittargetrobpoint3f__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__if_algorhmitroblinecloud__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[74];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tutorial_interfaces.msg._if_algorhmitroblinecloud.IfAlgorhmitroblinecloud", full_classname_dest, 73) == 0);
  }
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // lasertrackoutcloud
    PyObject * field = PyObject_GetAttrString(_pymsg, "lasertrackoutcloud");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'lasertrackoutcloud'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence__init(&(ros_message->lasertrackoutcloud), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tutorial_interfaces__msg__IfAlgorhmitrobpoint3f__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tutorial_interfaces__msg__IfAlgorhmitrobpoint3f * dest = ros_message->lasertrackoutcloud.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tutorial_interfaces__msg__if_algorhmitrobpoint3f__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // targetpointoutcloud
    PyObject * field = PyObject_GetAttrString(_pymsg, "targetpointoutcloud");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'targetpointoutcloud'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence__init(&(ros_message->targetpointoutcloud), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f * dest = ros_message->targetpointoutcloud.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tutorial_interfaces__msg__if_algorhmittargetrobpoint3f__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // solderjoints
    PyObject * field = PyObject_GetAttrString(_pymsg, "solderjoints");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->solderjoints = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__if_algorhmitroblinecloud__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IfAlgorhmitroblinecloud */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._if_algorhmitroblinecloud");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IfAlgorhmitroblinecloud");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__IfAlgorhmitroblinecloud * ros_message = (tutorial_interfaces__msg__IfAlgorhmitroblinecloud *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lasertrackoutcloud
    PyObject * field = NULL;
    size_t size = ros_message->lasertrackoutcloud.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tutorial_interfaces__msg__IfAlgorhmitrobpoint3f * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->lasertrackoutcloud.data[i]);
      PyObject * pyitem = tutorial_interfaces__msg__if_algorhmitrobpoint3f__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "lasertrackoutcloud", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // targetpointoutcloud
    PyObject * field = NULL;
    size_t size = ros_message->targetpointoutcloud.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tutorial_interfaces__msg__IfAlgorhmittargetrobpoint3f * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->targetpointoutcloud.data[i]);
      PyObject * pyitem = tutorial_interfaces__msg__if_algorhmittargetrobpoint3f__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "targetpointoutcloud", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // solderjoints
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->solderjoints ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "solderjoints", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
