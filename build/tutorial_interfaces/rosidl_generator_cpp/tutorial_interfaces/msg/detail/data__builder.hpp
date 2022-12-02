// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__DATA__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Data_my_data
{
public:
  Init_Data_my_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::msg::Data my_data(::tutorial_interfaces::msg::Data::_my_data_type arg)
  {
    msg_.my_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::Data>()
{
  return tutorial_interfaces::msg::builder::Init_Data_my_data();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__DATA__BUILDER_HPP_
