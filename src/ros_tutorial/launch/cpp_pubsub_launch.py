from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package="ros_tutorial",
            executable="talker",
            name="custom_msg_publisher",
            output="screen"
        ),

        launch_ros.actions.Node(
            package="ros_tutorial",
            executable="talkerandlistner",
            name="custom_msg_subscriber_to_another_topic",
            output="screen"
        )
    ])