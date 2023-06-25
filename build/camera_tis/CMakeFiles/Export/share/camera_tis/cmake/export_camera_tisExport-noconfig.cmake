#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "camera_tis::camera_tis" for configuration ""
set_property(TARGET camera_tis::camera_tis APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(camera_tis::camera_tis PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcamera_tis.so"
  IMPORTED_SONAME_NOCONFIG "libcamera_tis.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS camera_tis::camera_tis )
list(APPEND _IMPORT_CHECK_FILES_FOR_camera_tis::camera_tis "${_IMPORT_PREFIX}/lib/libcamera_tis.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
