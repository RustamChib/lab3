// Rustam Chibar
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>


float X,Y;

void joint4angleCallback(const std_msgs::Float64 msg)
{
	
	X = msg.data;
	ROS_INFO("X: %f", X); 		

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "rotate");
  
  ros::NodeHandle n;

  ros::Publisher pub3 = n.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 100);

  //ros::Subscriber sub3 = n.subscribe("rob403_Saltanat_desired_joint4_angle", 1000, joint4angleCallback);
  ros::Subscriber sub4 = n.subscribe("/robot/joint4_position_controller/command", 1000, joint4angleCallback);
  ros::Rate loop_rate(10); // 10 per 1 sec

  ros::Time startTime = ros::Time::now();
  
  Y = -200;
  
  while (ros::ok())
  {  
	
	X = -200.0 + rand() % 400;
    std_msgs::Float64 msg_to_send;
    
    if (X >= Y)
	{
		Y = X;
		msg_to_send.data = X*0.01;		
	
		pub3.publish(msg_to_send);
    
		ROS_INFO("Moving joint 4: %f", msg_to_send);
	}
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
