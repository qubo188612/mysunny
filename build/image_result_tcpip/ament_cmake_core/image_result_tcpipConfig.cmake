# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_image_result_tcpip_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED image_result_tcpip_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(image_result_tcpip_FOUND FALSE)
  elseif(NOT image_result_tcpip_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(image_result_tcpip_FOUND FALSE)
  endif()
  return()
endif()
set(_image_result_tcpip_CONFIG_INCLUDED TRUE)

# output package information
if(NOT image_result_tcpip_FIND_QUIETLY)
  message(STATUS "Found image_result_tcpip: 0.0.0 (${image_result_tcpip_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'image_result_tcpip' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${image_result_tcpip_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(image_result_tcpip_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${image_result_tcpip_DIR}/${_extra}")
endforeach()
