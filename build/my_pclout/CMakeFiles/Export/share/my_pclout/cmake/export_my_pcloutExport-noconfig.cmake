#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "my_pclout::my_pclout" for configuration ""
set_property(TARGET my_pclout::my_pclout APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(my_pclout::my_pclout PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmy_pclout.so"
  IMPORTED_SONAME_NOCONFIG "libmy_pclout.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS my_pclout::my_pclout )
list(APPEND _IMPORT_CHECK_FILES_FOR_my_pclout::my_pclout "${_IMPORT_PREFIX}/lib/libmy_pclout.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
