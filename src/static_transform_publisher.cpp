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
#include <cstdlib>
#include <functional>
#include <memory>
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "serverpublisher/msg/data.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/static_transform_broadcaster.h"

// #include "ros2_cpp_pubsub/msg/data.hpp"

#include "serverpublisher/srv/change_string.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

// Typedefs declared by using to improve code readability
using my_datatype = serverpublisher::msg::Data;

using PUBLISHER = rclcpp::Publisher<my_datatype>::SharedPtr;
using TIMER     = rclcpp::TimerBase::SharedPtr;
using CLIENT    = rclcpp::Client<serverpublisher::srv::ChangeString>::SharedPtr;
using SERVICE   = serverpublisher::srv::ChangeString;
using REQUEST   = serverpublisher::srv::ChangeString::Request;
using RESPONSE  = rclcpp::Client<SERVICE>::SharedFuture;
using std::placeholders::_1;

/**
 * @brief Class that publishes data to the topic /data
 * and calculates the static transformation between the world frame and
 * user given child frame's pose.
 */
class MinimalPublisher : public rclcpp::Node {
public:

  /**
   * @brief Construct a new Minimal Publisher object
   *
   */
  explicit MinimalPublisher(char *transformation[]) : Node(
      "static_transform_publisher"), count_(0)
  {
    // Create a publisher
    publisher_ = this->create_publisher<my_datatype>("data", 10);

    // Call back pointer for publisher
    auto call_back_ptr = std::bind(&MinimalPublisher::timer_callback, this);

    // Timer function to call the publisher after 500ms
    timer_ = this->create_wall_timer(500ms, call_back_ptr);

    // Static Broadcaster object
    tf_static_broadcaster_ =
      std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

    // Make the transformation
    this->make_transforms(transformation);
  }

private:

  /**
   * @brief Call back function that gets executed after every time delay
   * and publishes the string to /data topic
   */
  void timer_callback()
  {
    auto message = my_datatype();

    message.my_data = " Hi " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.my_data.c_str());

    publisher_->publish(message);
  }

  /**
   * @brief Calculate the transformation between the world frame
   * and user given child frame transformation
   *
   * @param transformation pose input from user
   */
  void make_transforms(char *transformation[])
  {
    // Geometry messages transform object
    geometry_msgs::msg::TransformStamped t;

    // Populate the data in the object
    t.header.stamp    = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id  = transformation[1];

    t.transform.translation.x = atof(transformation[2]);
    t.transform.translation.y = atof(transformation[3]);
    t.transform.translation.z = atof(transformation[4]);
    tf2::Quaternion q;

    // Calculate the quaternion
    q.setRPY(atof(transformation[5]), atof(transformation[6]),
             atof(transformation[7]));
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation to the broadcaster
    tf_static_broadcaster_->sendTransform(t);
  }

  // Variables
  rclcpp::TimerBase::SharedPtr timer_;
  std::shared_ptr<tf2_ros::StaticTransformBroadcaster>tf_static_broadcaster_;
  rclcpp::Publisher<my_datatype>::SharedPtr publisher_;
  size_t count_;
};

/**
 * @brief Main function that initializes the node
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
  auto logger = rclcpp::get_logger("logger");

  // Obtain parameters from command line arguments
  if (argc != 8)
  {
    RCLCPP_ERROR(
      logger,
      "Invalid number of parameters\nusage: "
      "$ ros2 run ros2_cpp_pubsub static_tf_publisher "
      "child_frame_name x y z roll pitch yaw");
    return 1;
  }

  // As the parent frame of the transform is `world`, it is
  // necessary to check that the frame name passed is different
  if (strcmp(argv[1], "world") == 0)
  {
    RCLCPP_INFO(logger, "Your static name cannot be 'world'");
    return 1;
  }

  // Initialize the node and spin the node to publish the data
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>(argv));
  rclcpp::shutdown();
  return 0;
}
