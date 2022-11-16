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
#include "tutorial_interfaces/msg/num.hpp"
using namespace std::chrono_literals;

/* The add function adds three integers from the request and gives the sum to the response, 
 * while notifying the console of its status using logs.
 */



class MinimalPublisher : public rclcpp::Node {
 public:
  MinimalPublisher()
  : Node("minimal_publisher") {
    publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("Life_iteration", 10);
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "Parameter description!";
    // The first line of this constructor creates a parameter with
    // the name Declare_life_parameter and a default value of Depression
    
    // The parameter type is INFERRED from the default value, so in this case it would be set to a string type.
    this->declare_parameter("Parameter_Publisher", "AnyStringValue", param_desc);

    //  the timer_ is initialized with a period of 1000ms, which causes the timer_callback function to be executed once a second.
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }
  private:
    void timer_callback() {
      auto message = tutorial_interfaces::msg::Num();
      message.a = 2;
      message.b = 4;
      message.c = 6;
      publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
};

void add(
  const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
  std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response> response) {
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
  "Incoming request\na: %ld" " b: %ld" " c: %ld",
  request->a, request->b, request->c);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
  "sent back response: [%ld]", (long int)response->sum);
  auto message = tutorial_interfaces::msg::Num();
  message.a = 2;
  message.b = 4;
  message.c = 6;
  // publisher_->publish(message);
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

  
  // std::make_shared<MinimalPublisher>();
  // rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
  // Spins the node, making the service available
  // rclcpp::spin(node);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::spin(node);
  rclcpp::shutdown();
}
