# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_serverpublisher_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED serverpublisher_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(serverpublisher_FOUND FALSE)
  elseif(NOT serverpublisher_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(serverpublisher_FOUND FALSE)
  endif()
  return()
endif()
set(_serverpublisher_CONFIG_INCLUDED TRUE)

# output package information
if(NOT serverpublisher_FIND_QUIETLY)
  message(STATUS "Found serverpublisher: 0.0.0 (${serverpublisher_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'serverpublisher' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${serverpublisher_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(serverpublisher_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${serverpublisher_DIR}/${_extra}")
endforeach()
