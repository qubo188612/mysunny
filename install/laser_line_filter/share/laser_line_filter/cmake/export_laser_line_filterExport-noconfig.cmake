#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "laser_line_filter::laser_line_filter" for configuration ""
set_property(TARGET laser_line_filter::laser_line_filter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(laser_line_filter::laser_line_filter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblaser_line_filter.so"
  IMPORTED_SONAME_NOCONFIG "liblaser_line_filter.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS laser_line_filter::laser_line_filter )
list(APPEND _IMPORT_CHECK_FILES_FOR_laser_line_filter::laser_line_filter "${_IMPORT_PREFIX}/lib/liblaser_line_filter.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
