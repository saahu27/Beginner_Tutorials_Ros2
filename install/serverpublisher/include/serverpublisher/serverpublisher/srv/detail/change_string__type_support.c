// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from serverpublisher:srv/ChangeString.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "serverpublisher/srv/detail/change_string__rosidl_typesupport_introspection_c.h"
#include "serverpublisher/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "serverpublisher/srv/detail/change_string__functions.h"
#include "serverpublisher/srv/detail/change_string__struct.h"


// Include directives for member types
// Member `input`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  serverpublisher__srv__ChangeString_Request__init(message_memory);
}

void serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_fini_function(void * message_memory)
{
  serverpublisher__srv__ChangeString_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_member_array[1] = {
  {
    "input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(serverpublisher__srv__ChangeString_Request, input),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_members = {
  "serverpublisher__srv",  // message namespace
  "ChangeString_Request",  // message name
  1,  // number of fields
  sizeof(serverpublisher__srv__ChangeString_Request),
  serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_member_array,  // message members
  serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_type_support_handle = {
  0,
  &serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_serverpublisher
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Request)() {
  if (!serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_type_support_handle.typesupport_identifier) {
    serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &serverpublisher__srv__ChangeString_Request__rosidl_typesupport_introspection_c__ChangeString_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "serverpublisher/srv/detail/change_string__rosidl_typesupport_introspection_c.h"
// already included above
// #include "serverpublisher/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "serverpublisher/srv/detail/change_string__functions.h"
// already included above
// #include "serverpublisher/srv/detail/change_string__struct.h"


// Include directives for member types
// Member `output`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  serverpublisher__srv__ChangeString_Response__init(message_memory);
}

void serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_fini_function(void * message_memory)
{
  serverpublisher__srv__ChangeString_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_member_array[1] = {
  {
    "output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(serverpublisher__srv__ChangeString_Response, output),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_members = {
  "serverpublisher__srv",  // message namespace
  "ChangeString_Response",  // message name
  1,  // number of fields
  sizeof(serverpublisher__srv__ChangeString_Response),
  serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_member_array,  // message members
  serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_type_support_handle = {
  0,
  &serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_serverpublisher
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Response)() {
  if (!serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_type_support_handle.typesupport_identifier) {
    serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &serverpublisher__srv__ChangeString_Response__rosidl_typesupport_introspection_c__ChangeString_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "serverpublisher/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "serverpublisher/srv/detail/change_string__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_members = {
  "serverpublisher__srv",  // service namespace
  "ChangeString",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_Request_message_type_support_handle,
  NULL  // response message
  // serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_Response_message_type_support_handle
};

static rosidl_service_type_support_t serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_type_support_handle = {
  0,
  &serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_serverpublisher
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString)() {
  if (!serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_type_support_handle.typesupport_identifier) {
    serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serverpublisher, srv, ChangeString_Response)()->data;
  }

  return &serverpublisher__srv__detail__change_string__rosidl_typesupport_introspection_c__ChangeString_service_type_support_handle;
}
