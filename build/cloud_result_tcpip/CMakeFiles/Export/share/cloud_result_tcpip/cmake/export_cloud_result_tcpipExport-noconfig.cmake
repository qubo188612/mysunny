#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cloud_result_tcpip::cloud_result_tcpip" for configuration ""
set_property(TARGET cloud_result_tcpip::cloud_result_tcpip APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cloud_result_tcpip::cloud_result_tcpip PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcloud_result_tcpip.so"
  IMPORTED_SONAME_NOCONFIG "libcloud_result_tcpip.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cloud_result_tcpip::cloud_result_tcpip )
list(APPEND _IMPORT_CHECK_FILES_FOR_cloud_result_tcpip::cloud_result_tcpip "${_IMPORT_PREFIX}/lib/libcloud_result_tcpip.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
