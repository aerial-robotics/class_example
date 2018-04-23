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

<<<<<<< HEAD
	std::cout << "Changed the shield for Harry!" << std::endl;
=======
	std::cout << "Changed the shield for Hermione!" << std::endl;
>>>>>>> 1e97789d41104ef2dc5e1c0cf5265b5181da17c5

	// ROS loop that starts callbacks/publishers
	ros::spin();

	return 0;
}