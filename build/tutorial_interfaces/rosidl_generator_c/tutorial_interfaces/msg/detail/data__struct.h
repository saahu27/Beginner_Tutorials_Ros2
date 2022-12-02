// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__DATA__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'my_data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Data in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__Data
{
  rosidl_runtime_c__String my_data;
} tutorial_interfaces__msg__Data;

// Struct for a sequence of tutorial_interfaces__msg__Data.
typedef struct tutorial_interfaces__msg__Data__Sequence
{
  tutorial_interfaces__msg__Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__DATA__STRUCT_H_
