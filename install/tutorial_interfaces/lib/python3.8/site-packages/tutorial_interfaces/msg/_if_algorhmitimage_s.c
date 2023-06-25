// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitimage.idl
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
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__struct.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitimage__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
bool tutorial_interfaces__msg__if_algorhmitrobpos__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tutorial_interfaces__msg__if_algorhmitrobpos__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__if_algorhmitimage__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
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
    assert(strncmp("tutorial_interfaces.msg._if_algorhmitimage.IfAlgorhmitimage", full_classname_dest, 59) == 0);
  }
  tutorial_interfaces__msg__IfAlgorhmitimage * ros_message = _ros_message;
  {  // image
    PyObject * field = PyObject_GetAttrString(_pymsg, "image");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->image)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // robpos
    PyObject * field = PyObject_GetAttrString(_pymsg, "robpos");
    if (!field) {
      return false;
    }
    if (!tutorial_interfaces__msg__if_algorhmitrobpos__convert_from_py(field, &ros_message->robpos)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__if_algorhmitimage__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IfAlgorhmitimage */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._if_algorhmitimage");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IfAlgorhmitimage");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__IfAlgorhmitimage * ros_message = (tutorial_interfaces__msg__IfAlgorhmitimage *)raw_ros_message;
  {  // image
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->image);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "image", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robpos
    PyObject * field = NULL;
    field = tutorial_interfaces__msg__if_algorhmitrobpos__convert_to_py(&ros_message->robpos);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robpos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
