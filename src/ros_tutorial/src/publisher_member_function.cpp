// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. 
 * rclcpp/rclcpp.hpp include which allows you to use the most common pieces of the ROS 2 system
 * std_msgs/msg/string.hpp, which includes the built-in message type you will use to publish data.
 * tutorial_interfaces/msg/num.hpp includes the custom built msg types in the tutorial interfaces.
 * 
 * */

// The next line creates the node class MinimalPublisher by inheriting from rclcpp::Node. 
// Every this in the code is referring to the node.
class MinimalPublisher : public rclcpp::Node {
 public:
  /* The public constructor names the node minimal_publisher and initializes count_ to 0. 
   * inside the constructor, the publisher is initialized with the custom int message type, 
   * the topic name Life iteration, and the required queue size to limit messages in the event of a backup.
   * Next, timer_ is initialized, which causes the timer_callback function to be executed twice a second.
  */

  MinimalPublisher()
  : Node("minimal_publisher"), count_(0) {
    publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("Life_iteration", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  /* The timer_callback function is where the message data is set and the messages are actually published. 
   * The RCLCPP_INFO macro ensures every published message is printed to the console.
   * */
  void timer_callback() {
    auto message = tutorial_interfaces::msg::Num();
    message.a = this->count_++;
    message.b = this->count_++;
    message.c = this->count_++;
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing Iteration: '" << message.a << "'");
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing Iteration: '" << message.b << "'");
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing Iteration: '" << message.c << "'");
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[]) {
  // Following the MinimalPublisher class is main, where the node actually executes. rclcpp::init
  // initializes ROS 2, and rclcpp::spin starts processing data from the node, including callbacks from the timer.
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}