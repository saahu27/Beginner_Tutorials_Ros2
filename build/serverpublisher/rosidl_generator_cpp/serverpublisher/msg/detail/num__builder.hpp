// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serverpublisher:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__NUM__BUILDER_HPP_
#define SERVERPUBLISHER__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serverpublisher/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serverpublisher
{

namespace msg
{

namespace builder
{

class Init_Num_c
{
public:
  explicit Init_Num_c(::serverpublisher::msg::Num & msg)
  : msg_(msg)
  {}
  ::serverpublisher::msg::Num c(::serverpublisher::msg::Num::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serverpublisher::msg::Num msg_;
};

class Init_Num_b
{
public:
  explicit Init_Num_b(::serverpublisher::msg::Num & msg)
  : msg_(msg)
  {}
  Init_Num_c b(::serverpublisher::msg::Num::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_Num_c(msg_);
  }

private:
  ::serverpublisher::msg::Num msg_;
};

class Init_Num_a
{
public:
  Init_Num_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_b a(::serverpublisher::msg::Num::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Num_b(msg_);
  }

private:
  ::serverpublisher::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serverpublisher::msg::Num>()
{
  return serverpublisher::msg::builder::Init_Num_a();
}

}  // namespace serverpublisher

#endif  // SERVERPUBLISHER__MSG__DETAIL__NUM__BUILDER_HPP_
