#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

// Largely copied from https://answers.ros.org/question/263090/how-to-have-subs-and-publisher-in-one-single-cpp/
// and http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
// and http://wiki.ros.org/evarobot_odometry/Tutorials/indigo/Writing%20a%20Simple%20Subscriber%20for%20Odometry
// and http://docs.ros.org/melodic/api/nav_msgs/html/msg/Odometry.html
// and http://docs.ros.org/api/geometry_msgs/html/msg/PoseStamped.html
class odom2point
{
  ros::NodeHandle n;
  ros::Subscriber odom_sub;
  ros::Publisher pose_pub;

  geometry_msgs::PoseStamped output_msg;

  void odomCallback(const nav_msgs::Odometry::ConstPtr &odom)
  {

    output_msg.pose = odom->pose.pose;
    output_msg.header = odom->header;


    pose_pub.publish(output_msg);
  }

public:
  odom2point()
  {
    odom_sub = n.subscribe("ground_truth_odom", 1000,  &odom2point::odomCallback,this);
    pose_pub = n.advertise<geometry_msgs::PoseStamped>("ground_truth_pose", 1000);
  }

  ~odom2point()
  {
  }
};

int main(int argc, char **argv)
{

  ros::init(argc, argv, "odom2point");
  odom2point test_ros;

  ros::spin();
  ros::shutdown();
  return 0;
}


