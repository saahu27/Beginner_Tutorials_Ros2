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
    param_desc.description = "This parameter is mine!";
    // The first line of this constructor creates a parameter with
    // the name my_parameter and a default value of world
    // The parameter type is inferred from the default value, so in this case it would be set to a string type.
    this->declare_parameter("my_parameter", "world", param_desc);

    //  the timer_ is initialized with a period of 1000ms, which causes the timer_callback function to be executed once a second.
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalParam::timer_callback, this));
  }

  void timer_callback()
  {
    std::string my_param =
      this->get_parameter("my_parameter").get_parameter_value().get<std::string>();

    RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str());

    std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("my_parameter", "world")};
    this->set_parameters(all_new_parameters);
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