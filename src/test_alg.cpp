#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/node_handle.h>
#include <mrs_msgs/Reference.h>

// void chatterCallback0(const std_msgs::String::ConstPtr& msg)
// {
//   ROS_INFO("I heard on /uav0/pose: [%s]", msg->data.c_str());
// }

void chatterCallback0(const mrs_msgs::Reference::ConstPtr& msg)
{
    ROS_INFO("I heard on /uav0/pose");
    ROS_INFO("\tx: %f, y: %f, z: %f, heading: %f", msg->position.x, msg->position.y,
                                                 msg->position.z, msg->heading);
}

void chatterCallback1(const mrs_msgs::Reference::ConstPtr& msg)
{
    ROS_INFO("I heard on /uav1/pose");
    ROS_INFO("\tx: %f, y: %f, z: %f, heading: %f", msg->position.x, msg->position.y,
                                                 msg->position.z, msg->heading);
}

void chatterCallback2(const mrs_msgs::Reference::ConstPtr& msg)
{
    ROS_INFO("I heard on /uav2/pose");
    ROS_INFO("\tx: %f, y: %f, z: %f, heading: %f", msg->position.x, msg->position.y,
                                                 msg->position.z, msg->heading);
}

int main( int argc, char** argv ){
    std::cout << "algorithm has started" << std::endl;
    ros::init(argc, argv, "test_alg");
    std::cout << "init ok" << std::endl;
    ros::NodeHandle nh;
    std::cout << "NodeHandle ok" << std::endl;
    ros::Rate rate(100);
    ros::Subscriber sub0 = nh.subscribe("/uav0/pose", 1000, chatterCallback0);
    ros::Subscriber sub1 = nh.subscribe("/uav", 1000, chatterCallback1);
    ros::Subscriber sub2 = nh.subscribe("/uav2/pose", 1000, chatterCallback2);
    std::cout << "subscribe ok" << std::endl;
    while(ros::ok()){
        
        ros::spin();
        rate.sleep();
        // std::cout << "spin ok" << std::endl;
    }
    std::cout << "algorithm has ended" << std::endl;
    return 0;
}