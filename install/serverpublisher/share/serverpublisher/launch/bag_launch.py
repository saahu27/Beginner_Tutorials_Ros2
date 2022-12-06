from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
import launch_ros.actions
from launch.substitutions import TextSubstitution
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
import launch

def generate_launch_description():

    record_all_topics = LaunchConfiguration('record_all_topics')

    return LaunchDescription([

        DeclareLaunchArgument(
                "Parameter_launch_argument", default_value=TextSubstitution(text=str("Parameter_launch")),
                description="Parameter launch default value"
            ),

        DeclareLaunchArgument(
            "log_level",
            default_value = TextSubstitution(text=str("WARN")),
            description="Logging level"
        ),

        DeclareLaunchArgument(
            'record_all_topics',
            default_value='True'
        ),

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="talkerandlistner",
            name="custom_msg_subscriber_to_No_Life_iteration_topic",
            output="screen",
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="talker",
            name="custom_msg_publisher_to_Life_iteration_topic",
            parameters=[
                {"Parameter_Publisher":  LaunchConfiguration('Parameter_launch_argument')}
            ],
            output="screen",
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="server",
            name="custom_server_to_add_three_ints",
            output="screen",
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),

        launch.actions.ExecuteProcess(
            condition=IfCondition(record_all_topics),
            cmd=['ros2', 'bag', 'record', '-o ros2_bag', '-a'],
            shell=True
        )
        
    ])