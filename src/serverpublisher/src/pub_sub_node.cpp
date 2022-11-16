/* @copyright
 * 
 */
// Include important C++ header files that provide class
// templates for useful operations.
#include <chrono>
#include <functional> // Arithmetic, comparisons, and logical operations
#include <memory> // Dynamic memory management
#include <string> // String functions
#include <cstdlib>
// ROS Client Library for C++
// Allows use of the most common elements of ROS 2
#include "rclcpp/rclcpp.hpp"
 
// Custom message type that will be used to publish data
#include "tutorial_interfaces/msg/num.hpp"

#include "tutorial_interfaces/srv/add_three_ints.hpp"
 
using std::placeholders::_1;
 
// Create the node class named PublishingSubscriber which inherits the attributes
// and methods of the rclcpp::Node class.
class PublisherSubscriber : public rclcpp::Node
{
  public:
    // Constructor creates a node named publishing_subscriber. 
    // The published message count is initialized to 0.
    PublisherSubscriber()
    : Node("publishing_subscribing")
    {
      // Create the subscription.
      // The topic_callback function executes whenever data is published
      // to the 'Life_iteration' topic.
      subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
      "Life_iteration", 10, std::bind(&PublisherSubscriber::topic_callback, this, _1));
             
      // Publisher publishes String messages to a topic named "addison2". 
      // The size of the queue is 10 messages.
      publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("No_Life_iteration",10);

    }
 
  private:
    // Receives the String message that is published over the topic
    void topic_callback(const tutorial_interfaces::msg::Num & msg) const
    {
      // Create a new message of type String
      auto message = tutorial_interfaces::msg::Num();
       
      // Set our message's data attribute
      message.a = msg.a;
      message.b = msg.b;
      message.c = msg.c;
 
      // Publish the message to the topic named "No_Life_iteration"
      publisher_->publish(message);
      if (msg.a < 3) {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"),"Cindition to call client not met yet");
      }
      if (msg.a > 3) {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Calling client for requesting addition of three numbers");
        Set_Client(msg);
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Came back from client to the call back");
      }
    }

    void Set_Client(const tutorial_interfaces::msg::Num & msg) const {

      RCLCPP_WARN_STREAM_ONCE(this->get_logger(), "Calling client \n");
      std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_client");
      rclcpp::Client<tutorial_interfaces::srv::AddThreeInts>::SharedPtr client =
      node->create_client<tutorial_interfaces::srv::AddThreeInts>("add_three_ints");
      // The while loop gives the client 1 second to search for service nodes in the network.
      // If it can’t find any, it will continue waiting.
      while (!client->wait_for_service()) {
        if (!rclcpp::ok()) {
          RCLCPP_ERROR_STREAM(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
        }
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
      }

      auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
      request->a = msg.a;
      request->b = msg.b;
      request->c = msg.c;

      auto result = client->async_send_request(request);

      // Wait for the result.
      if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "client recieved Sum: %ld", result.get()->sum);
      } else {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_three_ints");    // Error Log
      }
      
    }
    // Declare the subscription attribute
    rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
         
    // Declaration of the publisher_ attribute      
    rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;


   
};
 
// Node execution starts here
int main(int argc, char * argv[])
{
  // Initialize ROS 2
  rclcpp::init(argc, argv);
  
  // Start processing data from the node as well as the callbacks
  rclcpp::spin(std::make_shared<PublisherSubscriber>());
 
  // Shutdown the node when finished
  rclcpp::shutdown();
  return 0;
}