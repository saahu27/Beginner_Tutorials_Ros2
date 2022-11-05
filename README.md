# Beginner_Tutorials_Ros2

<<<<<<< HEAD
**Clone the Repository to workspace**

```
git clone https://github.com/saahu27/Beginner_Tutorials_Ros2/tree/ros_pub_sub
```

```
rosdep install -i --from-path src --rosdistro humble -y
```
```
colcon build --packages-select cpp_pubsub
```
```
. install/local_setup.bash
```
```
source /opt/ros/humble/setup.bash
```
```
ros2 run cpp_pubsub talker
```
In a Seperate Terminal:

```
ros2 run cpp_pubsub listner
```

# Static Code Analysis:
```
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/cpp_pubsub/src/*.cpp > ./Results/cpplint.txt
```
```
cppcheck --enable=all --std=c++17 src/cpp_pubsub/src/*.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression > ./Results/cppcheck.txt
```


# Install Colcon

A ROS workspace is a directory with a particular structure. Commonly there is a src subdirectory. Inside that subdirectory is where the source code of ROS packages will be located. Typically the directory starts otherwise empty.

colcon does out of source builds So you can keep your files without the src directory.
 
=======
[Ros Commandline arguments](https://design.ros2.org/articles/ros_command_line_arguments.html#name-remapping-rules)

[Beginner CLI Tools](http://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools.html#)

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
>>>>>>> main
```
sudo apt install python3-colcon-common-extensions
```

<<<<<<< HEAD
Directory structure
```
.
└── src
    └── examples
        ├── CONTRIBUTING.md
        ├── LICENSE
        ├── rclcpp
        ├── rclpy
        └── README.md

4 directories, 3 files
```
# Build using colcon

Navigate to Root of the directory. In the root of the workspace, run colcon build. Since build types such as ament_cmake do not support the concept of the devel space and require the package to be installed, colcon supports the option --symlink-install.
=======
Colcon Build
>>>>>>> main
```
colcon build --symlink-install
```

<<<<<<< HEAD
# Run Tests
```
colcon test
```
To see results of tests:
```
colcon test-result
```

```
colcon test-result --verbose
```

# Format

```
ament_clang_format
```

To format changes directly
```
ament_clang_format --reformat
```


# Source env

When colcon has completed building successfully, the output will be in the install directory. Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths. colcon will have generated bash/bat files in the install directory to help setup the environment. These files will add all of the required elements to your path and library paths as well as provide any bash or shell commands exported by packages.

```
. install/setup.bash
```

# Run a Demo

```
ros2 run examples_rclcpp_minimal_subscriber subscriber_member_function
```
# Create your own package

colcon uses the package.xml specification defined in REP 149 (format 2 is also supported).

colcon supports multiple build types. The recommended build types are ament_cmake and ament_python. Also supported are pure cmake packages.

An example of an ament_python build is the ament_index_python package , where the setup.py is the primary entry point for building.

A package such as demo_nodes_cpp uses the ament_cmake build type, and uses CMake as the build tool.

For convenience, you can use the tool ros2 pkg create to create a new package based on a template

# Colcon cd

The command colcon_cd allows you to quickly change the current working directory of your shell to the directory of a package. As an example colcon_cd some_ros_package would quickly bring you to the directory ~/ros2_install/src/some_ros_package.

one time 
```
echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
echo "export _colcon_cd_root=/opt/ros/humble/" >> ~/.bashrc
```

```
colcon_cd some_ros_package
```
# Setup colcon tab completion

The command colcon supports command completion for bash and bash-like shells if the colcon-argcomplete package is installed.

```
echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
```

# Tips
Tips

1. If you do not want to build a specific package place an empty file named COLCON_IGNORE in the directory and it will not be indexed.

2. If you want to avoid configuring and building tests in CMake packages you can pass: --cmake-args -DBUILD_TESTING=0.

3. If you want to run a single particular test from a package:
=======
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
to run a Particular test:
>>>>>>> main
```
colcon test --packages-select YOUR_PKG_NAME --ctest-args -R YOUR_TEST_IN_PKG
```

<<<<<<< HEAD
# Create workspace
 
## source

=======
Install setup:
```
. install/setup.bash
````

setup colcon CD:
```
echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
echo "export _colcon_cd_root=/opt/ros/humble/" >> ~/.bashrc
```
Setup colcon tab completion:
```
echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
```

2. [Creating workspace](http://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html)

Source
>>>>>>> main
```
source /opt/ros/humble/setup.bash
```

<<<<<<< HEAD
## Create a new directory

Best practice is to create a new directory for every new workspace. The name doesn’t matter, but it is helpful to have it indicate the purpose of the workspace. Let’s choose the directory name ros2_ws, for development workspace:
```
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```

## Resolve dependencies

Before building the workspace, you need to resolve package dependencies. You may have all the dependencies already, but best practice is to check for dependencies every time you clone. You wouldn’t want a build to fail after a long wait because of missing dependencies.

From the root of your workspace (ros2_ws), run the following command:
```
rosdep install -i --from-path src --rosdistro humble -y
```

If you installed ROS 2 on Linux from source or the “fat” archive, you will need to use the rosdep command from their installation instructions. Here are the from-source rosdep section and the “fat” archive rosdep section.

If you already have all your dependencies, the console will return:
```
#All required rosdeps installed successfully
```

## Build using colcon
```
colcon build
```

To build specific packages :

```
colcon build --packages-select cpp_pubsub
```

Other useful arguments for colcon build:

    --packages-up-to builds the package you want, plus all its dependencies, but not the whole workspace (saves time)

    --symlink-install saves you from having to rebuild every time you tweak python scripts

    --event-handlers console_direct+ shows console output while building (can otherwise be found in the log directory)

Once the build is finished, enter ls in the workspace root (~/ros2_ws) and you will see that colcon has created new directories:
```
build  install  log  src
```
 ## Source the overlay

Before sourcing the overlay, it is very important that you open a new terminal, separate from the one where you built the workspace. Sourcing an overlay in the same terminal where you built, or likewise building where an overlay is sourced, may create complex issues.

```
source /opt/ros/humble/setup.bash
```
In the roor of your ws:
```
. install/local_setup.bash
```

# Create Package

Make sure you are in the src folder before running the package creation command.
```
cd ~/ros2_ws/src
```

```
ros2 pkg create --build-type ament_cmake <package_name>
```

the optional argument --node-name which creates a simple Hello World type executable in the package.
```
ros2 pkg create --build-type ament_cmake --node-name my_node my_package 
```

Build a package 
=======
Resolve Dependencies:
```
# Root of your workspace
rosdep install -i --from-path src --rosdistro humble -y
```

3. [Create Package](http://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html)

Directory Structure:
```
workspace_folder/
    src/
      package_1/
          CMakeLists.txt
          package.xml

      package_2/
          setup.py
          package.xml
          resource/package_2
      ...
      package_n/
          CMakeLists.txt
          package.xml
```

**Source the workspace.**

The command syntax for creating a new package in ROS 2 is:
```
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
```
You will now have a new folder within your workspace’s src directory called my_package.

Build:
>>>>>>> main
```
colcon build --packages-select my_package
```
```
<<<<<<< HEAD
. install/local_setup.bash
```

Using the Package
=======
#source set up file.
. install/local_setup.bash
```
Run the Package:
>>>>>>> main
```
ros2 run my_package my_node
```

<<<<<<< HEAD
# tips
After the standard C++ headers is the rclcpp/rclcpp.hpp include which allows you to use the most common pieces of the ROS 2 system. Last is std_msgs/msg/string.hpp, which includes the built-in message type you will use to publish data.

# Build Example

```
cd beginner_tutorials
rosdep install -i --from-path src --rosdistro humble -y
colcon build
. install/setup.bash
ros2 run cpp_pubsub talker
```

open a new terminal, source it from
```
. <ros2_installation_directory>/install/setup.bash
```
Run the Subscriber node
```
ros2 run cpp_pubsub listner
```

# Cpplint and Cppcheck

Form the root of the folder

```
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/cpp_pubsub/src/*.cpp > ./Results/cpplint.txt
```

```
cppcheck --enable=all --std=c++17 src/cpp_pubsub/src/*.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression > ./results/cppcheck.txt
```