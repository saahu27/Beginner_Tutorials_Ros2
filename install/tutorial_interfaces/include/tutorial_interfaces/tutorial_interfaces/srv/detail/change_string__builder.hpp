// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
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
  ::tutorial_interfaces::srv::ChangeString_Request input(::tutorial_interfaces::srv::ChangeString_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::ChangeString_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::ChangeString_Request>()
{
  return tutorial_interfaces::srv::builder::Init_ChangeString_Request_input();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
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
  ::tutorial_interfaces::srv::ChangeString_Response output(::tutorial_interfaces::srv::ChangeString_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::ChangeString_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::ChangeString_Response>()
{
  return tutorial_interfaces::srv::builder::Init_ChangeString_Response_output();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
