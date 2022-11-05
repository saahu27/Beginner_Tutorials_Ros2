
[Ros Commandline arguments](https://design.ros2.org/articles/ros_command_line_arguments.html#name-remapping-rules)

# [Beginner CLI Tools](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools.html#)

1. [Configure Environment](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Configuring-ROS2-Environment.html)

Source :

```
source /opt/ros/humble/setup.bash
```

2. [Using turtlesim and rqt](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Introducing-Turtlesim/Introducing-Turtlesim.html)

Install : 
```
sudo apt update

sudo apt install ros-humble-turtlesim
```

example to run ros2 node:

```
ros2 run turtlesim turtlesim_node
```

```
ros2 run <package_name> <package_node>
```

Install rqt:
```
sudo apt update

sudo apt install ~nros-humble-rqt*
```

To run rqt:
```
rqt
```

3. [Ros2 Nodes](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Nodes/Understanding-ROS2-Nodes.html)

![Nodes](../Nodes-TopicandService.gif "Nodes")

Node list:
```
ros2 node list
```

Node info:
```
ros2 node info <node_name>
```

Remapping

Remapping allows you to reassign default node properties, like node name, topic names, service names, etc., to custom values.
Name remapping rules:

Remapping rules may be introduced using the --remap/-r option. This option takes a single from:=to remapping rule.

As an example, to remap from foo to bar for some_ros_executable, one may execute:
```
ros2 run some_package some_ros_executable --ros-args --remap some_node:foo:=bar
```
4. [Ros2 Topics](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Topics/Understanding-ROS2-Topics.html)

![Ros2 Topic](../Nodes-TopicandService.gif)

rqt graph:
```
rqt_graph
```

ros2 topic list:
```
ros2 topic list -t
```

ros2 topic echo:
```
ros2 topic echo <topic_name>
```

ros2 topic info
```
ros2 topic info <topic_name>
```
ros2 interface show:
```
ros2 interface show <msg type>
```
ros2 topic publish :
The '<args>' argument is the actual data you’ll pass to the topic. It’s important to note that this argument needs to be input in YAML syntax. 
```
ros2 topic pub <topic_name> <msg_type> '<args>'
```
additional tags:
```
--once (publish once), --rate 1(1 hz frequency)
```
example msg type:
```
linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
  ---
```

```
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

rate at which data is published:
```
ros2 topic hz <topic_name>
```
5. [Services](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Services/Understanding-ROS2-Services.html)

Services are another method of communication for nodes in the ROS graph. Services are based on a call-and-response model, versus topics’ publisher-subscriber model. While topics allow nodes to subscribe to data streams and get continual updates, services only provide data when they are specifically called by a client.

ros2 service list:
```
ros2 service list
```
To see the types of all the active services at the same time, you can append the --show-types option, abbreviated as -t, to the list command
```
ros2 service list -t
```
Find service type:
```
ros2 service type <service_name>
```
find all the services of a specific type
```
ros2 service find <type_name>
```
eg :
```
Service    Type
/spawn [turtlesim/srv/Spawn]
````

Service -> Type.

To see the arguments in a Service. ros interface show:
```
ros2 interface show <type_name>
```

to find a service’s type, and how to find the structure of that type’s arguments, you can call a service using
```
ros2 service call <service_name> <service_type> <arguments>
```
arguments part is optional

6. [Ros2 parameters](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Parameters/Understanding-ROS2-Parameters.html)

rosparam list:
```
ros2 param list
```
display the type and current value of a parameter
```
ros2 param get <node_name> <parameter_name>
```

change a parameter’s value at runtime
```
ros2 param set <node_name> <parameter_name> <value>
```
view all of a node’s current parameter values:
```
ros2 param dump <node_name>
```
The command prints to the standard output (stdout) by default but you can also redirect the parameter values into a file to save them for later. (use:  > ./file_name to save the output. This will be the parameter file.)

load parameters from a file to a currently running node
```
ros2 param load <node_name> <parameter_file>
```

start the same node using your saved parameter values
```
ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>
```

7. [Actions](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Actions/Understanding-ROS2-Actions.html)

Actions are one of the communication types in ROS 2 and are intended for long running tasks. They consist of three parts: a goal, feedback, and a result.

Actions are built on topics and services. Their functionality is similar to services, except actions can be canceled. They also provide steady feedback, as opposed to services which return a single response.

Actions use a client-server model, similar to the publisher-subscriber model (described in the topics tutorial). An “action client” node sends a goal to an “action server” node that acknowledges the goal and returns a stream of feedback and a result.
![Action](../Action-SingleActionClient.gif)

Ros2 action list with type:
```
ros2 action list -t
```

Info:
```
ros2 action info <action_name>
```

Ros2 action send goal:
```
ros2 action send_goal <action_name> <action_type> <values>
```
values need to be in YAML format. eg: "{theta: 1.57}".
To see the feedback of this goal, add --feedback


8. [rqt_console](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Using-Rqt-Console/Using-Rqt-Console.html)

To open :
```
ros2 run rqt_console rqt_console
```

9. [Launching Nodes](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Launching-Multiple-Nodes/Launching-Multiple-Nodes.html)

```
ros2 launch <Pkg_name> <launchnode_name>
```

10. [Recoding Data](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Recording-And-Playing-Back-Data/Recording-And-Playing-Back-Data.html)

To Install:
```
sudo apt-get install ros-humble-ros2bag \
ros-humble-rosbag2-storage-default-plugins
```

To Record:
```
ros2 bag record <topic_name>
```

To Record Multiple topics:
```
ros2 bag record -o subset /turtle1/cmd_vel /turtle1/pose
```
The -o option allows you to choose a unique name for your bag file. The following string, in this case subset, is the file name.

Ros bag info:
```
ros2 bag info <bag_file_name>
```
Ros bag play:
```
ros2 bag play subset
```

[Beginner Client Libraries](http://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries.html)

1. [Colcon Build](http://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html)

Compared to catkin there is no devel directory. **colcon does out of source builds**. ament_cmake do not support the concept of the devel space and require the package to be installed.colcon supports the option --symlink-install. This allows the installed files to be changed by changing the files in the source space

Install colcon:
```
sudo apt install python3-colcon-common-extensions
```

Colcon Build
```
colcon build --symlink-install
```

Directory Structure
```
.
├── build
├── install
├── log
└── src

4 directories, 0 files
```
To run Tests:
```
colcon test
```
To see test results:
```
colcon test-result --verbose
```
Install setup:
```
. install/setup.bash
````
