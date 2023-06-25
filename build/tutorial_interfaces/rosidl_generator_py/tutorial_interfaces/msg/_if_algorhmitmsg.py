# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IfAlgorhmitmsg(type):
    """Metaclass of message 'IfAlgorhmitmsg'."""

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
                'tutorial_interfaces.msg.IfAlgorhmitmsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__if_algorhmitmsg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__if_algorhmitmsg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__if_algorhmitmsg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__if_algorhmitmsg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__if_algorhmitmsg

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmitpoint2f
            if IfAlgorhmitpoint2f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmitpoint2f.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmitrobpos
            if IfAlgorhmitrobpos.__class__._TYPE_SUPPORT is None:
                IfAlgorhmitrobpos.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmittargetpoint2f
            if IfAlgorhmittargetpoint2f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmittargetpoint2f.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IfAlgorhmitmsg(metaclass=Metaclass_IfAlgorhmitmsg):
    """Message class 'IfAlgorhmitmsg'."""

    __slots__ = [
        '_result',
        '_imageout',
        '_targetpointout',
        '_lasertrackout',
        '_robpos',
        '_solderjoints',
    ]

    _fields_and_field_types = {
        'result': 'boolean',
        'imageout': 'sensor_msgs/Image',
        'targetpointout': 'sequence<tutorial_interfaces/IfAlgorhmittargetpoint2f>',
        'lasertrackout': 'sequence<tutorial_interfaces/IfAlgorhmitpoint2f>',
        'robpos': 'tutorial_interfaces/IfAlgorhmitrobpos',
        'solderjoints': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmittargetpoint2f')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmitpoint2f')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmitrobpos'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', bool())
        from sensor_msgs.msg import Image
        self.imageout = kwargs.get('imageout', Image())
        self.targetpointout = kwargs.get('targetpointout', [])
        self.lasertrackout = kwargs.get('lasertrackout', [])
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
        if self.result != other.result:
            return False
        if self.imageout != other.imageout:
            return False
        if self.targetpointout != other.targetpointout:
            return False
        if self.lasertrackout != other.lasertrackout:
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
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'result' field must be of type 'bool'"
        self._result = value

    @property
    def imageout(self):
        """Message field 'imageout'."""
        return self._imageout

    @imageout.setter
    def imageout(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'imageout' field must be a sub message of type 'Image'"
        self._imageout = value

    @property
    def targetpointout(self):
        """Message field 'targetpointout'."""
        return self._targetpointout

    @targetpointout.setter
    def targetpointout(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmittargetpoint2f
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
                 all(isinstance(v, IfAlgorhmittargetpoint2f) for v in value) and
                 True), \
                "The 'targetpointout' field must be a set or sequence and each value of type 'IfAlgorhmittargetpoint2f'"
        self._targetpointout = value

    @property
    def lasertrackout(self):
        """Message field 'lasertrackout'."""
        return self._lasertrackout

    @lasertrackout.setter
    def lasertrackout(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmitpoint2f
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
                 all(isinstance(v, IfAlgorhmitpoint2f) for v in value) and
                 True), \
                "The 'lasertrackout' field must be a set or sequence and each value of type 'IfAlgorhmitpoint2f'"
        self._lasertrackout = value

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
