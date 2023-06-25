# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:msg/IfAlgorhmitrobpos.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IfAlgorhmitrobpos(type):
    """Metaclass of message 'IfAlgorhmitrobpos'."""

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
                'tutorial_interfaces.msg.IfAlgorhmitrobpos')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__if_algorhmitrobpos
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__if_algorhmitrobpos
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__if_algorhmitrobpos
            cls._TYPE_SUPPORT = module.type_support_msg__msg__if_algorhmitrobpos
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__if_algorhmitrobpos

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IfAlgorhmitrobpos(metaclass=Metaclass_IfAlgorhmitrobpos):
    """Message class 'IfAlgorhmitrobpos'."""

    __slots__ = [
        '_header',
        '_posx',
        '_posy',
        '_posz',
        '_posrx',
        '_posry',
        '_posrz',
        '_posout1',
        '_posout2',
        '_posout3',
        '_toolid',
        '_tcpid',
        '_usertcpid',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'posx': 'float',
        'posy': 'float',
        'posz': 'float',
        'posrx': 'float',
        'posry': 'float',
        'posrz': 'float',
        'posout1': 'float',
        'posout2': 'float',
        'posout3': 'float',
        'toolid': 'int32',
        'tcpid': 'int32',
        'usertcpid': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.posx = kwargs.get('posx', float())
        self.posy = kwargs.get('posy', float())
        self.posz = kwargs.get('posz', float())
        self.posrx = kwargs.get('posrx', float())
        self.posry = kwargs.get('posry', float())
        self.posrz = kwargs.get('posrz', float())
        self.posout1 = kwargs.get('posout1', float())
        self.posout2 = kwargs.get('posout2', float())
        self.posout3 = kwargs.get('posout3', float())
        self.toolid = kwargs.get('toolid', int())
        self.tcpid = kwargs.get('tcpid', int())
        self.usertcpid = kwargs.get('usertcpid', int())

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
        if self.posx != other.posx:
            return False
        if self.posy != other.posy:
            return False
        if self.posz != other.posz:
            return False
        if self.posrx != other.posrx:
            return False
        if self.posry != other.posry:
            return False
        if self.posrz != other.posrz:
            return False
        if self.posout1 != other.posout1:
            return False
        if self.posout2 != other.posout2:
            return False
        if self.posout3 != other.posout3:
            return False
        if self.toolid != other.toolid:
            return False
        if self.tcpid != other.tcpid:
            return False
        if self.usertcpid != other.usertcpid:
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
    def posx(self):
        """Message field 'posx'."""
        return self._posx

    @posx.setter
    def posx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posx' field must be of type 'float'"
        self._posx = value

    @property
    def posy(self):
        """Message field 'posy'."""
        return self._posy

    @posy.setter
    def posy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posy' field must be of type 'float'"
        self._posy = value

    @property
    def posz(self):
        """Message field 'posz'."""
        return self._posz

    @posz.setter
    def posz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posz' field must be of type 'float'"
        self._posz = value

    @property
    def posrx(self):
        """Message field 'posrx'."""
        return self._posrx

    @posrx.setter
    def posrx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posrx' field must be of type 'float'"
        self._posrx = value

    @property
    def posry(self):
        """Message field 'posry'."""
        return self._posry

    @posry.setter
    def posry(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posry' field must be of type 'float'"
        self._posry = value

    @property
    def posrz(self):
        """Message field 'posrz'."""
        return self._posrz

    @posrz.setter
    def posrz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posrz' field must be of type 'float'"
        self._posrz = value

    @property
    def posout1(self):
        """Message field 'posout1'."""
        return self._posout1

    @posout1.setter
    def posout1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posout1' field must be of type 'float'"
        self._posout1 = value

    @property
    def posout2(self):
        """Message field 'posout2'."""
        return self._posout2

    @posout2.setter
    def posout2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posout2' field must be of type 'float'"
        self._posout2 = value

    @property
    def posout3(self):
        """Message field 'posout3'."""
        return self._posout3

    @posout3.setter
    def posout3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posout3' field must be of type 'float'"
        self._posout3 = value

    @property
    def toolid(self):
        """Message field 'toolid'."""
        return self._toolid

    @toolid.setter
    def toolid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'toolid' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'toolid' field must be an integer in [-2147483648, 2147483647]"
        self._toolid = value

    @property
    def tcpid(self):
        """Message field 'tcpid'."""
        return self._tcpid

    @tcpid.setter
    def tcpid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tcpid' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'tcpid' field must be an integer in [-2147483648, 2147483647]"
        self._tcpid = value

    @property
    def usertcpid(self):
        """Message field 'usertcpid'."""
        return self._usertcpid

    @usertcpid.setter
    def usertcpid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'usertcpid' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'usertcpid' field must be an integer in [-2147483648, 2147483647]"
        self._usertcpid = value
