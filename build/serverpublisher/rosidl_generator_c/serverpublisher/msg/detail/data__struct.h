// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serverpublisher:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__DATA__STRUCT_H_
#define SERVERPUBLISHER__MSG__DETAIL__DATA__STRUCT_H_

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

/// Struct defined in msg/Data in the package serverpublisher.
typedef struct serverpublisher__msg__Data
{
  rosidl_runtime_c__String my_data;
} serverpublisher__msg__Data;

// Struct for a sequence of serverpublisher__msg__Data.
typedef struct serverpublisher__msg__Data__Sequence
{
  serverpublisher__msg__Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serverpublisher__msg__Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVERPUBLISHER__MSG__DETAIL__DATA__STRUCT_H_
