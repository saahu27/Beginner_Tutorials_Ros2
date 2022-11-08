#include <chrono>
#include <functional>
#include <string>

#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

// class MinimalParam : public rclcpp::Node
// {
// public:
//   MinimalParam()
//   : Node("minimal_param_node")
//   {
//     this->declare_parameter("my_parameter", "world");

//     timer_ = this->create_wall_timer(
//       1000ms, std::bind(&MinimalParam::timer_callback, this));
//   }

// ...

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("minimal_param_node")
  {
    // Descriptors allow you to specify a text description of the parameter and its constraints, like making it read-only, specifying a range, etc. 
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "I Want to know the feeling of life!";
    // The first line of this constructor creates a parameter with
    // the name Declare_life_parameter and a default value of Depression
    
    // The parameter type is INFERRED from the default value, so in this case it would be set to a string type.
    this->declare_parameter("Declare_life_parameter", "Depression", param_desc);

    //  the timer_ is initialized with a period of 1000ms, which causes the timer_callback function to be executed once a second.
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalParam::timer_callback, this));
  }

  void timer_callback()
  {
    
    RCLCPP_DEBUG_STREAM(this->get_logger(), " getting parameter value \n");
    std::string my_param =
      this->get_parameter("Declare_life_parameter").get_parameter_value().get<std::string>();

    RCLCPP_ERROR_STREAM_ONCE(this->get_logger(), "Parameter Not Created Yet; Yet asked for parameter value; value set from launch or cpp \n ");

    RCLCPP_INFO(this->get_logger(), "what do you want to do: %s!", my_param.c_str());

    std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("Declare_life_parameter", " set it to default \n ")};
    this->set_parameters(all_new_parameters);
    RCLCPP_WARN_STREAM_ONCE(this->get_logger(), "Initialized parameter after sending the parameter; \n");
    
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}