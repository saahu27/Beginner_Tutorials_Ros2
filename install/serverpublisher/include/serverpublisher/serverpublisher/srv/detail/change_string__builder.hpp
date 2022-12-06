// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serverpublisher:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
#define SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serverpublisher/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serverpublisher
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Request_input
{
public:
  Init_ChangeString_Request_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serverpublisher::srv::ChangeString_Request input(::serverpublisher::srv::ChangeString_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serverpublisher::srv::ChangeString_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::serverpublisher::srv::ChangeString_Request>()
{
  return serverpublisher::srv::builder::Init_ChangeString_Request_input();
}

}  // namespace serverpublisher


namespace serverpublisher
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Response_output
{
public:
  Init_ChangeString_Response_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serverpublisher::srv::ChangeString_Response output(::serverpublisher::srv::ChangeString_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serverpublisher::srv::ChangeString_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::serverpublisher::srv::ChangeString_Response>()
{
  return serverpublisher::srv::builder::Init_ChangeString_Response_output();
}

}  // namespace serverpublisher

#endif  // SERVERPUBLISHER__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
