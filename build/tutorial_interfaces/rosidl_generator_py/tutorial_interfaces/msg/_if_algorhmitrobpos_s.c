// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
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
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__struct.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitrobpos__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__if_algorhmitrobpos__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
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
    assert(strncmp("tutorial_interfaces.msg._if_algorhmitrobpos.IfAlgorhmitrobpos", full_classname_dest, 61) == 0);
  }
  tutorial_interfaces__msg__IfAlgorhmitrobpos * ros_message = _ros_message;
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
  {  // posx
    PyObject * field = PyObject_GetAttrString(_pymsg, "posx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posy
    PyObject * field = PyObject_GetAttrString(_pymsg, "posy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posy = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posz
    PyObject * field = PyObject_GetAttrString(_pymsg, "posz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posrx
    PyObject * field = PyObject_GetAttrString(_pymsg, "posrx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posrx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posry
    PyObject * field = PyObject_GetAttrString(_pymsg, "posry");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posry = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posrz
    PyObject * field = PyObject_GetAttrString(_pymsg, "posrz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posrz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posout1
    PyObject * field = PyObject_GetAttrString(_pymsg, "posout1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posout1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posout2
    PyObject * field = PyObject_GetAttrString(_pymsg, "posout2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posout2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posout3
    PyObject * field = PyObject_GetAttrString(_pymsg, "posout3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posout3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // toolid
    PyObject * field = PyObject_GetAttrString(_pymsg, "toolid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->toolid = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // tcpid
    PyObject * field = PyObject_GetAttrString(_pymsg, "tcpid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tcpid = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // usertcpid
    PyObject * field = PyObject_GetAttrString(_pymsg, "usertcpid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->usertcpid = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__if_algorhmitrobpos__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IfAlgorhmitrobpos */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._if_algorhmitrobpos");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IfAlgorhmitrobpos");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__IfAlgorhmitrobpos * ros_message = (tutorial_interfaces__msg__IfAlgorhmitrobpos *)raw_ros_message;
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
  {  // posx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posrx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posrx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posrx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posry
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posry);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posry", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posrz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posrz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posrz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posout1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posout1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posout1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posout2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posout2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posout2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posout3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posout3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posout3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toolid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->toolid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toolid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tcpid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->tcpid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tcpid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // usertcpid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->usertcpid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "usertcpid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
