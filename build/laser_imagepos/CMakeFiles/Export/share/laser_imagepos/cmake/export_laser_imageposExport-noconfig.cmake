#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "laser_imagepos::laser_imagepos" for configuration ""
set_property(TARGET laser_imagepos::laser_imagepos APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(laser_imagepos::laser_imagepos PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblaser_imagepos.so"
  IMPORTED_SONAME_NOCONFIG "liblaser_imagepos.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS laser_imagepos::laser_imagepos )
list(APPEND _IMPORT_CHECK_FILES_FOR_laser_imagepos::laser_imagepos "${_IMPORT_PREFIX}/lib/liblaser_imagepos.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
