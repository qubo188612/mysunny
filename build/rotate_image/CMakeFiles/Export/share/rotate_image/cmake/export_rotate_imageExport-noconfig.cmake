#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rotate_image::rotate_image" for configuration ""
set_property(TARGET rotate_image::rotate_image APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rotate_image::rotate_image PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librotate_image.so"
  IMPORTED_SONAME_NOCONFIG "librotate_image.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rotate_image::rotate_image )
list(APPEND _IMPORT_CHECK_FILES_FOR_rotate_image::rotate_image "${_IMPORT_PREFIX}/lib/librotate_image.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
