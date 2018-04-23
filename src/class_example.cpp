// Cpp libraries
#include <ros/ros.h>

// Service type (for toggling shield)
#include "mg_msgs/SetQuadBool.h"

int main(int argc, char** argv){
	ros::init(argc, argv, "class_example");
	ros::NodeHandle node("~");

	// Create service client
	ros::ServiceClient shield_client = 
		node.serviceClient<mg_msgs::SetQuadBool>("/mediation_layer/set_quad_shield");
	mg_msgs::SetQuadBool srv_msg;
	srv_msg.request.set_bool = 1;
	srv_msg.request.quad_name = "ron";
	shield_client.call(srv_msg);

	std::cout << "Changed the shield for Ron2!" << std::endl;

	// ROS loop that starts callbacks/publishers
	ros::spin();

	return 0;
}