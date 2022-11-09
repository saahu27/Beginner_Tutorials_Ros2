[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
# Beginner_Tutorials_Ros2

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
 
```
sudo apt install python3-colcon-common-extensions
```

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
```
colcon build --symlink-install
```

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
```
colcon test --packages-select YOUR_PKG_NAME --ctest-args -R YOUR_TEST_IN_PKG
```

# Create workspace
 
## source

```
source /opt/ros/humble/setup.bash
```

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
```
colcon build --packages-select my_package
```
```
. install/local_setup.bash
```

Using the Package
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
