/* @copyright
 * 
 */
// Include important C++ header files that provide class
// templates for useful operations.
#include <chrono>
#include <functional> // Arithmetic, comparisons, and logical operations
#include <memory> // Dynamic memory management
#include <string> // String functions
 
// ROS Client Library for C++
// Allows use of the most common elements of ROS 2
#include "rclcpp/rclcpp.hpp"
 
// Custom message type that will be used to publish data
#include "tutorial_interfaces/msg/num.hpp"
 
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
      // to the 'addison' topic.
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