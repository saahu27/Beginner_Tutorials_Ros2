/**
 *  @copyright (c) 2021 Sahruday
 *  @file    add_two_ints_server.cpp
 *  @author  Sahruday 
 *
 *  @brief Header
 *
 */

#include <memory>

#include "tutorial_interfaces/srv/add_three_ints.hpp"
#include "rclcpp/rclcpp.hpp"

/* The add function adds three integers from the request and gives the sum to the response, 
 * while notifying the console of its status using logs.
 */

void add(
  const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
  std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response> response) {
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
  "Incoming request\na: %ld" " b: %ld" " c: %ld",
  request->a, request->b, request->c);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
  "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char ** argv) {
  // Initializes ROS 2 C++ client library
  rclcpp::init(argc, argv);
  // Creates a node named add_three_ints_server
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_server");

  // Creates a service named add_three_ints for that node and automatically advertises it over the networks with the &add method
  rclcpp::Service<tutorial_interfaces::srv::AddThreeInts>::SharedPtr service =
    node->create_service<tutorial_interfaces::srv::AddThreeInts>("add_three_ints", &add);

  // Prints a log message when it’s ready
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add three ints.");

  // Spins the node, making the service available
  rclcpp::spin(node);
  rclcpp::shutdown();
}
