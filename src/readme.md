# Running serverpublisher package

Tha package has three nodes, 
one publisher(talker) publishes to topic Life_iteration 3 numbers (count value of iteration 3 times) of custom type specified in tutorial interfaces. It also has a paremetr set from launch arg which only publishes and runs all these nodes if only a condition matches.
The other executable subscribes to this topic, and creates a client and waits for the service. 
the other is a server, which adds three its and returns sum. 
once service sends a response, the client accepts publishes the three ints to another topic called No_life_iteration. and displays sum.

The second launch argument specifies the log level for the nodes.

To Download Package
```
git clone
```

Resolve dependencies; build and source:

```
rosdep install -i --from-path src --rosdistro humble -y
colcon build
. install/setup.bash
```
**any string value except "AnyStringValue" will execute the nodes.**
```
ros2 launch serverpublisher cpp_pubsub_launch.py Parameter_launch_argument:="any string value" log_level:="INFO"
```
To see the output published to the other topic; In a new terminal, source it and run to see the message in the new topic.
```
ros2 topic echo /No_Life_iteration
```