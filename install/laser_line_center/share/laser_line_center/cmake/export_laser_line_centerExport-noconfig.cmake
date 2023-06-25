#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "laser_line_center::laser_line_center" for configuration ""
set_property(TARGET laser_line_center::laser_line_center APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(laser_line_center::laser_line_center PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblaser_line_center.so"
  IMPORTED_SONAME_NOCONFIG "liblaser_line_center.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS laser_line_center::laser_line_center )
list(APPEND _IMPORT_CHECK_FILES_FOR_laser_line_center::laser_line_center "${_IMPORT_PREFIX}/lib/liblaser_line_center.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
