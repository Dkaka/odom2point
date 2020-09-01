# odom2point

This ROS package converts [nav_msgs](http://docs.ros.org/melodic/api/nav_msgs/html/index-msg.html)/Odometry Message message to [geometry_msgs](https://docs.ros.org/api/geometry_msgs/html/index-msg.html)/PoseStamped Message.

Initially made for use gazebo p3d plugin with supereight_ros.

It is tested under Melodic and the husky robot or simulator.

Run using the command `roslaunch odom2point converter.launch`

Change the default source and destination topic names accordingly in the launch file.

### Ground truth pose message from gazebo

One example of generating the ground truth pose of the camera is to use the p3d plugin in gazebo. For instance, by adding the following lines in the .gazebo file or urdf file for the camera:

```xml
<gazebo>
  <plugin name="ground_truth" filename="libgazebo_ros_p3d.so">
    <robotNamespace>$(arg robot_namespace)</robotNamespace>
    <frameName>map</frameName>
    <bodyName>camera_link</bodyName>
    <topicName>pose_ground_truth</topicName>
    <updateRate>60.0</updateRate>
  </plugin>
</gazebo>
```

Then the ground truth message will be published at topic `pose_ground_truth`.
