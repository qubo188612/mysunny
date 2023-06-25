#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "modbus::modbus" for configuration ""
set_property(TARGET modbus::modbus APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(modbus::modbus PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmodbus.so"
  IMPORTED_SONAME_NOCONFIG "libmodbus.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS modbus::modbus )
list(APPEND _IMPORT_CHECK_FILES_FOR_modbus::modbus "${_IMPORT_PREFIX}/lib/libmodbus.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
