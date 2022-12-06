// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serverpublisher:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define SERVERPUBLISHER__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serverpublisher/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serverpublisher
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::serverpublisher::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::serverpublisher::msg::Sphere radius(::serverpublisher::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serverpublisher::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::serverpublisher::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::serverpublisher::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serverpublisher::msg::Sphere>()
{
  return serverpublisher::msg::builder::Init_Sphere_center();
}

}  // namespace serverpublisher

#endif  // SERVERPUBLISHER__MSG__DETAIL__SPHERE__BUILDER_HPP_
