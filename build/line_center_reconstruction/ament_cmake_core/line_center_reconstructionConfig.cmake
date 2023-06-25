# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_line_center_reconstruction_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED line_center_reconstruction_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(line_center_reconstruction_FOUND FALSE)
  elseif(NOT line_center_reconstruction_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(line_center_reconstruction_FOUND FALSE)
  endif()
  return()
endif()
set(_line_center_reconstruction_CONFIG_INCLUDED TRUE)

# output package information
if(NOT line_center_reconstruction_FIND_QUIETLY)
  message(STATUS "Found line_center_reconstruction: 0.0.0 (${line_center_reconstruction_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'line_center_reconstruction' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${line_center_reconstruction_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(line_center_reconstruction_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${line_center_reconstruction_DIR}/${_extra}")
endforeach()
