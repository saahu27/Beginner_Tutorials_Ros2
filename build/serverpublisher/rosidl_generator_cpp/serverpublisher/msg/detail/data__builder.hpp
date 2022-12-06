// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serverpublisher:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__DATA__BUILDER_HPP_
#define SERVERPUBLISHER__MSG__DETAIL__DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serverpublisher/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serverpublisher
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
  ::serverpublisher::msg::Data my_data(::serverpublisher::msg::Data::_my_data_type arg)
  {
    msg_.my_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serverpublisher::msg::Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serverpublisher::msg::Data>()
{
  return serverpublisher::msg::builder::Init_Data_my_data();
}

}  // namespace serverpublisher

#endif  // SERVERPUBLISHER__MSG__DETAIL__DATA__BUILDER_HPP_
