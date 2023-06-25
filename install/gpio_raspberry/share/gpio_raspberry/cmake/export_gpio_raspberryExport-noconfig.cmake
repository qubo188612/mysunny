#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gpio_raspberry::gpio_raspberry" for configuration ""
set_property(TARGET gpio_raspberry::gpio_raspberry APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(gpio_raspberry::gpio_raspberry PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libgpio_raspberry.so"
  IMPORTED_SONAME_NOCONFIG "libgpio_raspberry.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS gpio_raspberry::gpio_raspberry )
list(APPEND _IMPORT_CHECK_FILES_FOR_gpio_raspberry::gpio_raspberry "${_IMPORT_PREFIX}/lib/libgpio_raspberry.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
