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

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using std::placeholders::_1;

/* node is named minimal_subscriber, and the constructor uses the node’s create_subscription class to execute the callback.
 * There is no timer because the subscriber simply responds whenever data is published to the topic topic.(Depeneds on the function it does right?)
 * 
 * 
 * The topic_callback function receives the string message data published over the topic, 
 *  and simply writes it to the console using the RCLCPP_INFO macro.
 */
class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
      "Life iteration", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

 private:
  void topic_callback(const tutorial_interfaces::msg::Num & msg) const {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.num << "'");
  }
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
