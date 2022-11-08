from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="Life_launch_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"Declare_life_parameter": " Depression_launch"}
            ],
            remappings=[
            ("Depression", "Using_remappings")
        ]
        )
    ])