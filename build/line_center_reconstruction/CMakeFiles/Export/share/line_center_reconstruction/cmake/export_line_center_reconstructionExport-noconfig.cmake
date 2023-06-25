#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "line_center_reconstruction::line_center_reconstruction" for configuration ""
set_property(TARGET line_center_reconstruction::line_center_reconstruction APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(line_center_reconstruction::line_center_reconstruction PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libline_center_reconstruction.so"
  IMPORTED_SONAME_NOCONFIG "libline_center_reconstruction.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS line_center_reconstruction::line_center_reconstruction )
list(APPEND _IMPORT_CHECK_FILES_FOR_line_center_reconstruction::line_center_reconstruction "${_IMPORT_PREFIX}/lib/libline_center_reconstruction.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
