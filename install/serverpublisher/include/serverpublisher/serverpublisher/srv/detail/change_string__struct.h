// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serverpublisher:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__STRUCT_H_
#define SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'input'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeString in the package serverpublisher.
typedef struct serverpublisher__srv__ChangeString_Request
{
  rosidl_runtime_c__String input;
} serverpublisher__srv__ChangeString_Request;

// Struct for a sequence of serverpublisher__srv__ChangeString_Request.
typedef struct serverpublisher__srv__ChangeString_Request__Sequence
{
  serverpublisher__srv__ChangeString_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serverpublisher__srv__ChangeString_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'output'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeString in the package serverpublisher.
typedef struct serverpublisher__srv__ChangeString_Response
{
  rosidl_runtime_c__String output;
} serverpublisher__srv__ChangeString_Response;

// Struct for a sequence of serverpublisher__srv__ChangeString_Response.
typedef struct serverpublisher__srv__ChangeString_Response__Sequence
{
  serverpublisher__srv__ChangeString_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serverpublisher__srv__ChangeString_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__STRUCT_H_
