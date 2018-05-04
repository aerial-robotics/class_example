// Cpp libraries
#include <ros/ros.h>

// Service type (for toggling shield)
#include "std_msgs/Empty.h"

void GameStartCallback(const std_msgs::Empty& empty_msg) {
	std::cout << "When you play the game of drones, you pop the balloon, or you die!" << std::endl;
}


int main(int argc, char** argv){
	ros::init(argc, argv, "callback_example");
	ros::NodeHandle node("~");

	// Create service client
	ros::Subscriber sub = node.subscribe("/mediation_layer/Start_Game", 1, 
		                               GameStartCallback);

	std::cout << "I will wait for the game to start..." << std::endl;

	// ROS loop that starts callbacks/publishers
	ros::spin();

	return 0;
}