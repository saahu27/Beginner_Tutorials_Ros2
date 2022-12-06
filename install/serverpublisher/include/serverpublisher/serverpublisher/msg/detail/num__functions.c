// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serverpublisher:msg/Num.idl
// generated code does not contain a copyright notice
#include "serverpublisher/msg/detail/num__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
serverpublisher__msg__Num__init(serverpublisher__msg__Num * msg)
{
  if (!msg) {
    return false;
  }
  // a
  // b
  // c
  return true;
}

void
serverpublisher__msg__Num__fini(serverpublisher__msg__Num * msg)
{
  if (!msg) {
    return;
  }
  // a
  // b
  // c
}

bool
serverpublisher__msg__Num__are_equal(const serverpublisher__msg__Num * lhs, const serverpublisher__msg__Num * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // c
  if (lhs->c != rhs->c) {
    return false;
  }
  return true;
}

bool
serverpublisher__msg__Num__copy(
  const serverpublisher__msg__Num * input,
  serverpublisher__msg__Num * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  // c
  output->c = input->c;
  return true;
}

serverpublisher__msg__Num *
serverpublisher__msg__Num__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serverpublisher__msg__Num * msg = (serverpublisher__msg__Num *)allocator.allocate(sizeof(serverpublisher__msg__Num), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serverpublisher__msg__Num));
  bool success = serverpublisher__msg__Num__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serverpublisher__msg__Num__destroy(serverpublisher__msg__Num * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serverpublisher__msg__Num__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serverpublisher__msg__Num__Sequence__init(serverpublisher__msg__Num__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serverpublisher__msg__Num * data = NULL;

  if (size) {
    data = (serverpublisher__msg__Num *)allocator.zero_allocate(size, sizeof(serverpublisher__msg__Num), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serverpublisher__msg__Num__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serverpublisher__msg__Num__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
serverpublisher__msg__Num__Sequence__fini(serverpublisher__msg__Num__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      serverpublisher__msg__Num__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

serverpublisher__msg__Num__Sequence *
serverpublisher__msg__Num__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serverpublisher__msg__Num__Sequence * array = (serverpublisher__msg__Num__Sequence *)allocator.allocate(sizeof(serverpublisher__msg__Num__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serverpublisher__msg__Num__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serverpublisher__msg__Num__Sequence__destroy(serverpublisher__msg__Num__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serverpublisher__msg__Num__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serverpublisher__msg__Num__Sequence__are_equal(const serverpublisher__msg__Num__Sequence * lhs, const serverpublisher__msg__Num__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serverpublisher__msg__Num__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serverpublisher__msg__Num__Sequence__copy(
  const serverpublisher__msg__Num__Sequence * input,
  serverpublisher__msg__Num__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serverpublisher__msg__Num);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    serverpublisher__msg__Num * data =
      (serverpublisher__msg__Num *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serverpublisher__msg__Num__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          serverpublisher__msg__Num__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serverpublisher__msg__Num__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
