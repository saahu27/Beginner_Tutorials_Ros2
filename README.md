
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

## Clone and Build the package
- Clone this repository. this package is your workspace.
Make sure that your terminal is sourced
- Run the below commands:

```
cd beginner_tutorials_Ros2
source /opt/ros/humble/setup.bash
rosdep install -i --from-path src --rosdistro humble -y
colcon build
. install/setup.bash
```

## Commands to source a new Terminal window
- When a new terminal is opened, please source your terminal using
```
. <ros2_installation_directory>/install/setup.bash
. install/setup.bash
```

## Run Server, Subscriber-Publisher-Client, Parameter Publisher

Server - adds three integers and sends back response
Parameter Publisher - takes a parameter value and constantly updates it and publisher to a topic called Life_iteration.
Subscriber-Publisher-Client - subscribes to the topic Life_iteration and then calls client and publishes to no_life_iteration topic. It only pubslishes after the count of "a" gets to 30.

The 
Using launch file
```
ros2 launch serverpublisher cpp_pubsub_launch.py Parameter_launch_argument:="any string value" log_level:="INFO"
```
To see the output published to the other topic; In a new terminal, source it and run to see the message in the new topic.
```
ros2 topic echo /No_Life_iteration
```

Using command line arguments:
```
ros2 run serverpublisher talker --ros-args --log-level INFO
```
In new terminal:
```
ros2 param set /minimal_publisher Parameter_Publisher "Sahruday"
```

```
ros2 run serverpublisher server --ros-args --log-level INFO
```
in new terminal
```
ros2 service call /add_three_ints tutorial_interfaces/srv/AddThreeInts "{a: 1,b: 2, c: 3}"
```

in new terminal:
```
ros2 run serverpublisher talkerandlistner --ros-args --log-level INFO
```

## Using rqt_console to visualize the log messages:
Run the below command in a new terminal
```
ros2 run rqt_console rqt_console
```


## Static Code Analysis
### cpplint
Run the below command from inside the package folder `beginner_tutorials`
```
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/*.cpp &> Results/cpplint.txt
```
### cppcheck
Run the below command from the project root folder `beginner_tutorials`
```
cppcheck --enable=all --std=c++17 src/*.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression > Results/cppcheck.txt
```

Publish a static transform using ROS2 TF2

Run the static transform publisher that publishes the data to /data topic and also converts the static transformation between world frame and child frame.
To run the node, use the below command
```
ros2 run learning_tf2_cpp static_transform_publisher talk 0.1 0.2 1 2 3 1
```

Use the tf2_ros to output the transformation to the console.

```
ros2 run tf2_ros tf2_echo world talk
```
or 
```
ros2 topic echo /tf_static
```
To save the frames and their relation in the pdf, run the below command

```
ros2 run tf2_tools view_frames
```

Change string server 
```
ros2 run serverpublisher stringserver

```
```
ros2 service call /change_strings tutorial_interfaces/srv/ChangeString "{input: 'Hello world'}"
```

To record a ros bag, run this launch file and terminate after 10 seconds.
```
ros2 launch serverpublisher bag_launch.py Parameter_launch_argument:="any string value" log_level:="INFO" record_all_topics:=True
```

To play the rosbag :

```
ros2 launch serverpublisher rosbag_launch.py
```
```
ros2 bag play ros2_bag
```
