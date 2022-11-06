from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package="serverpublisher",
            executable="talker",
            name="custom_msg_publisher_to_Life_iteration_topic",
            output="screen"
        ),

        launch_ros.actions.Node(
            package="serverpublisher",
            executable="server",
            name="custom_server_to_add_three_ints",
            output="screen"
        ),


        launch_ros.actions.Node(
            package="serverpublisher",
            executable="talkerandlistner",
            name="custom_msg_subscriber_to_No_Life_iteration_topic",
            output="screen"
        )
    ])