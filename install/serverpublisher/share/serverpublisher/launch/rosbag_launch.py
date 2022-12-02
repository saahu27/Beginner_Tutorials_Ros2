from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
import launch_ros.actions
from launch.substitutions import TextSubstitution
from launch.substitutions import LaunchConfiguration



def generate_launch_description():
    return LaunchDescription([

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="talkerandlistner",
            name="custom_msg_subscriber_to_No_Life_iteration_topic",
            output="screen",
        ),

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="server",
            name="custom_server_to_add_three_ints",
            output="screen",
        )
        
    ])