// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from serverpublisher:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef SERVERPUBLISHER__MSG__DETAIL__DATA__TRAITS_HPP_
#define SERVERPUBLISHER__MSG__DETAIL__DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "serverpublisher/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace serverpublisher
{

namespace msg
{

inline void to_flow_style_yaml(
  const Data & msg,
  std::ostream & out)
{
  out << "{";
  // member: my_data
  {
    out << "my_data: ";
    rosidl_generator_traits::value_to_yaml(msg.my_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: my_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_data: ";
    rosidl_generator_traits::value_to_yaml(msg.my_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Data & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace serverpublisher

namespace rosidl_generator_traits
{

[[deprecated("use serverpublisher::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const serverpublisher::msg::Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  serverpublisher::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use serverpublisher::msg::to_yaml() instead")]]
inline std::string to_yaml(const serverpublisher::msg::Data & msg)
{
  return serverpublisher::msg::to_yaml(msg);
}

template<>
inline const char * data_type<serverpublisher::msg::Data>()
{
  return "serverpublisher::msg::Data";
}

template<>
inline const char * name<serverpublisher::msg::Data>()
{
  return "serverpublisher/msg/Data";
}

template<>
struct has_fixed_size<serverpublisher::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<serverpublisher::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<serverpublisher::msg::Data>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SERVERPUBLISHER__MSG__DETAIL__DATA__TRAITS_HPP_
