// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from serverpublisher:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__SPHERE__FUNCTIONS_H_
#define SERVERPUBLISHER__MSG__DETAIL__SPHERE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "serverpublisher/msg/rosidl_generator_c__visibility_control.h"

#include "serverpublisher/msg/detail/sphere__struct.h"

/// Initialize msg/Sphere message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * serverpublisher__msg__Sphere
 * )) before or use
 * serverpublisher__msg__Sphere__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__init(serverpublisher__msg__Sphere * msg);

/// Finalize msg/Sphere message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
void
serverpublisher__msg__Sphere__fini(serverpublisher__msg__Sphere * msg);

/// Create msg/Sphere message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * serverpublisher__msg__Sphere__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
serverpublisher__msg__Sphere *
serverpublisher__msg__Sphere__create();

/// Destroy msg/Sphere message.
/**
 * It calls
 * serverpublisher__msg__Sphere__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
void
serverpublisher__msg__Sphere__destroy(serverpublisher__msg__Sphere * msg);

/// Check for msg/Sphere message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__are_equal(const serverpublisher__msg__Sphere * lhs, const serverpublisher__msg__Sphere * rhs);

/// Copy a msg/Sphere message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__copy(
  const serverpublisher__msg__Sphere * input,
  serverpublisher__msg__Sphere * output);

/// Initialize array of msg/Sphere messages.
/**
 * It allocates the memory for the number of elements and calls
 * serverpublisher__msg__Sphere__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__Sequence__init(serverpublisher__msg__Sphere__Sequence * array, size_t size);

/// Finalize array of msg/Sphere messages.
/**
 * It calls
 * serverpublisher__msg__Sphere__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
void
serverpublisher__msg__Sphere__Sequence__fini(serverpublisher__msg__Sphere__Sequence * array);

/// Create array of msg/Sphere messages.
/**
 * It allocates the memory for the array and calls
 * serverpublisher__msg__Sphere__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
serverpublisher__msg__Sphere__Sequence *
serverpublisher__msg__Sphere__Sequence__create(size_t size);

/// Destroy array of msg/Sphere messages.
/**
 * It calls
 * serverpublisher__msg__Sphere__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
void
serverpublisher__msg__Sphere__Sequence__destroy(serverpublisher__msg__Sphere__Sequence * array);

/// Check for msg/Sphere message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__Sequence__are_equal(const serverpublisher__msg__Sphere__Sequence * lhs, const serverpublisher__msg__Sphere__Sequence * rhs);

/// Copy an array of msg/Sphere messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_serverpublisher
bool
serverpublisher__msg__Sphere__Sequence__copy(
  const serverpublisher__msg__Sphere__Sequence * input,
  serverpublisher__msg__Sphere__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SERVERPUBLISHER__MSG__DETAIL__SPHERE__FUNCTIONS_H_
