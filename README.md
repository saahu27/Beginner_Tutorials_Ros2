# server Client

# Build Example

```
cd beginner_tutorials
rosdep install -i --from-path src --rosdistro humble -y
colcon build --packages-select cpp_srvcli
. install/setup.bash
ros2 run cpp_srvcli server
```

open a new terminal, source it from
```
. <ros2_installation_directory>/install/setup.bash
```
Run the Servicenode
```
ros2 run cpp_srvcli client 2 3
```

# Cpplint and Cppcheck

Form the root of the folder

```
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/cpp_srvcli/src/*.cpp >> ./Results/cpplint.txt
```

```
cppcheck --enable=all --std=c++17 src/cpp_srvcli/src/*.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression > ./results/cppcheck.txt
```

# Custom msgs

```
rosdep install -i --from-path src --rosdistro humble -y
. install/setup.bash
colcon build --packages-select cpp_pubsub
ros2 run cpp_pubsub talker
```

in other terminal
```
ros2 run cpp_pubsub listener
```

# Server Client

```
colcon build --packages-select cpp_srvcli
ros2 run cpp_srvcli server
```

in other Terminal
```
ros2 run cpp_srvcli client 2 3 1
```