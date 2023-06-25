# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IfAlgorhmitcloud(type):
    """Metaclass of message 'IfAlgorhmitcloud'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.msg.IfAlgorhmitcloud')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__if_algorhmitcloud
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__if_algorhmitcloud
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__if_algorhmitcloud
            cls._TYPE_SUPPORT = module.type_support_msg__msg__if_algorhmitcloud
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__if_algorhmitcloud

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmitpoint4f
            if IfAlgorhmitpoint4f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmitpoint4f.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmitrobpos
            if IfAlgorhmitrobpos.__class__._TYPE_SUPPORT is None:
                IfAlgorhmitrobpos.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmittargetpoint4f
            if IfAlgorhmittargetpoint4f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmittargetpoint4f.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IfAlgorhmitcloud(metaclass=Metaclass_IfAlgorhmitcloud):
    """Message class 'IfAlgorhmitcloud'."""

    __slots__ = [
        '_header',
        '_lasertrackoutcloud',
        '_targetpointoutcloud',
        '_robpos',
        '_solderjoints',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'lasertrackoutcloud': 'sequence<tutorial_interfaces/IfAlgorhmitpoint4f>',
        'targetpointoutcloud': 'sequence<tutorial_interfaces/IfAlgorhmittargetpoint4f>',
        'robpos': 'tutorial_interfaces/IfAlgorhmitrobpos',
        'solderjoints': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmitpoint4f')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmittargetpoint4f')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmitrobpos'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.lasertrackoutcloud = kwargs.get('lasertrackoutcloud', [])
        self.targetpointoutcloud = kwargs.get('targetpointoutcloud', [])
        from tutorial_interfaces.msg import IfAlgorhmitrobpos
        self.robpos = kwargs.get('robpos', IfAlgorhmitrobpos())
        self.solderjoints = kwargs.get('solderjoints', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.lasertrackoutcloud != other.lasertrackoutcloud:
            return False
        if self.targetpointoutcloud != other.targetpointoutcloud:
            return False
        if self.robpos != other.robpos:
            return False
        if self.solderjoints != other.solderjoints:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def lasertrackoutcloud(self):
        """Message field 'lasertrackoutcloud'."""
        return self._lasertrackoutcloud

    @lasertrackoutcloud.setter
    def lasertrackoutcloud(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmitpoint4f
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, IfAlgorhmitpoint4f) for v in value) and
                 True), \
                "The 'lasertrackoutcloud' field must be a set or sequence and each value of type 'IfAlgorhmitpoint4f'"
        self._lasertrackoutcloud = value

    @property
    def targetpointoutcloud(self):
        """Message field 'targetpointoutcloud'."""
        return self._targetpointoutcloud

    @targetpointoutcloud.setter
    def targetpointoutcloud(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmittargetpoint4f
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, IfAlgorhmittargetpoint4f) for v in value) and
                 True), \
                "The 'targetpointoutcloud' field must be a set or sequence and each value of type 'IfAlgorhmittargetpoint4f'"
        self._targetpointoutcloud = value

    @property
    def robpos(self):
        """Message field 'robpos'."""
        return self._robpos

    @robpos.setter
    def robpos(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmitrobpos
            assert \
                isinstance(value, IfAlgorhmitrobpos), \
                "The 'robpos' field must be a sub message of type 'IfAlgorhmitrobpos'"
        self._robpos = value

    @property
    def solderjoints(self):
        """Message field 'solderjoints'."""
        return self._solderjoints

    @solderjoints.setter
    def solderjoints(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'solderjoints' field must be of type 'bool'"
        self._solderjoints = value
