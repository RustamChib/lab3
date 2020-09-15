// Rustam Chibar
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>


float func;

void joint4angleCallback(const std_msgs::Float64 msg)
{
	
	func = msg.data;
	ROS_INFO("func: %f", func); 		

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "rotate");
  
  ros::NodeHandle n;

  ros::Publisher pub3 = n.advertise<std_msgs::Float64>("/robot/joint5_position_controller/command", 100);
  ros::Subscriber sub4 = n.subscribe("/robot/joint5_position_controller/command", 1000, joint4angleCallback);
  ros::Rate loop_rate(10); // 10 per 1 sec

  ros::Time startTime = ros::Time::now();
  
  	  float i = 0.00;
  while (ros::ok())
  {  

	    func = sin(i);
		
		std_msgs::Float64 msg_to_send;

		msg_to_send.data = func;		
	
		pub3.publish(msg_to_send);
    
		ROS_INFO("Moving joint 5: %f", msg_to_send);
		i = i + 0.05;

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
