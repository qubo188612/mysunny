# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_gpio_raspberry_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED gpio_raspberry_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(gpio_raspberry_FOUND FALSE)
  elseif(NOT gpio_raspberry_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(gpio_raspberry_FOUND FALSE)
  endif()
  return()
endif()
set(_gpio_raspberry_CONFIG_INCLUDED TRUE)

# output package information
if(NOT gpio_raspberry_FIND_QUIETLY)
  message(STATUS "Found gpio_raspberry: 0.0.0 (${gpio_raspberry_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'gpio_raspberry' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${gpio_raspberry_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(gpio_raspberry_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${gpio_raspberry_DIR}/${_extra}")
endforeach()
