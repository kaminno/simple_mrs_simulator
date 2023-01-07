#include <iostream>

#include <chrono>
#include <thread>
#include <ctime>

#include <vector>
#include <string>
#include <map>
#include <random>
#include <list>
#include "robot.h"

#include "robot_simulator.h"
// #include <stdlib.h>
#include "boost/numeric/odeint.hpp"

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <ros/node_handle.h>
#include "std_msgs/String.h"
#include "mrs_msgs/Reference.h"
#include <sstream>

using namespace std;
using namespace boost::numeric::odeint;

typedef runge_kutta_dopri5< double > stepper_type;

int main( int argc, char** argv ){

    ros::init(argc, argv, "simulation_test");
    ros::NodeHandle nh;
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);
    // ros::Rate r(30);
    
    std::vector<string> compulsory_default_parameters_keys{"use_random_indexing", "start_at_random_positions",
                "use_default_linear_velocities", "use_default_angular_velocities", "use_default_linear_accelerations",
                "use_default_angular_accelerations", "use_default_headings", "use_default_maximal_horizontal_linear_velocity",
                "use_default_maximal_vertical_linear_velocity", "use_default_maximal_angular_velocity",
                "use_default_maximal_horizontal_linear_acceleration", "use_default_maximal_vertical_linear_acceleration",
                "use_default_maximal_angular_acceleration"};
    std::map<string, bool> compulsory_default_parameters_choices;
    for(string key: compulsory_default_parameters_keys){
        bool ok = nh.getParam("simulation_node/" + key, compulsory_default_parameters_choices[key]);
        if(!ok){
            std::cerr << "ERROR, parameter " << key << " is missing or has wrong value!" << std::endl;
            return 1;
        }
    }

    int uav_count;
    bool ok = nh.getParam("simulation_node/uav_count", uav_count);
    if(!ok || uav_count <= 0){
        std::cerr << "ERROR, parameter uav_count is missing or has wrong value!" << std::endl;
        return 1;
    }

    std::cout << "Parameters was loaded successfully." << std::endl;
    std::cout << "uav_count = " << uav_count << std::endl;
    for(std::map<string, bool>::iterator it = compulsory_default_parameters_choices.begin(); it != compulsory_default_parameters_choices.end(); ++it){
        std::cout << it->first << " = " << it->second << std::endl;
    }
    // bool use_random_indexing;
    // bool start_at_random_positions;
    // bool use_default_linear_velocities;
    // bool use_default_angular_velocities;
    // bool use_default_linear_accelerations;
    // bool use_default_angular_accelerations;
    // bool use_default_headings;
    // bool use_default_maximal_horizontal_linear_velocity;
    // bool use_default_maximal_vertical_linear_velocity;
    // bool use_default_maximal_angular_velocity;
    // bool use_default_maximal_horizontal_linear_acceleration;
    // bool use_default_maximal_vertical_linear_acceleration;
    // bool use_default_maximal_angular_acceleration;
    
    std::cout << "===== simulation started =====" << std::endl;
    
    RobotSimulator*rs = new RobotSimulator();
    // Robot* uavs[uav_count];
    std::vector<Robot*> uavs;
    std::map<Robot*, ros::Publisher> publishers;
    double lower_bound = 0;
    double upper_bound = 15;
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    for(int i = 0; i < uav_count; i++){
        double x = unif(re);
        double y = unif(re);
        double z = unif(re);
        // uavs[i] = new Robot(x, y, z);
        // uavs[i]->printS();
        uavs.push_back(new Robot(x, y, z));
        uavs.back()->printS();
        publishers[uavs.back()] = nh.advertise<mrs_msgs::Reference>("/uav" + std::to_string(uavs.back()->getId()) + "/pose", 10);
    }

    // ros::Publisher mrs_pub = nh.advertise<mrs_msgs::Reference>("mrs_ref", 10);
    int i = 0;
    while(ros::ok()){
        i++;
        for(Robot* drone : uavs){
            // position publisher
            // ros::Publisher uav_pub = nh.advertise<std_msgs::String>("/uav" + std::to_string(drone->getId()) + "/pose", 10);
            // uav_pub = nh.advertise<std_msgs::String>("/uav" + std::to_string(drone->getId()) + "/pose", 10);
            // ros::Publisher uav_pub = publishers[drone->getId()];
            // ros::Publisher uav_pub = publishers[drone];
            // std_msgs::String msg;
            // std::stringstream ss;
            // ss << "uav " << drone->getId() << " sent";
            // msg.data = ss.str();
            // ROS_INFO("%s", msg.data.c_str());
            // std::cout << "/uav" + std::to_string(drone->getId()) + "/pose" << std::endl;
            // uav_pub.publish(msg);
            // ros::spinOnce();
            //
            ros::Publisher uav_pub = publishers[drone];
            mrs_msgs::Reference ref;
            ref.heading = drone->getCurrentHeading();
            ref.position.x = drone->getCurrentPosition().getX();
            ref.position.y = drone->getCurrentPosition().getY();
            ref.position.z = drone->getCurrentPosition().getZ();
            // ROS_INFO("heading: %f", ref.heading);
            ROS_INFO("uav %d x: %f", drone->getId(), ref.position.x);
            uav_pub.publish(ref);
            //
            visualization_msgs::Marker points;
            points.header.frame_id = "simulation";
            points.header.stamp = ros::Time::now();
            points.ns = "simulation_test";
            points.action = visualization_msgs::Marker::ADD;
            // points.pose.orientation.w = 1.0;
            points.id = drone->getId();
            // points.type = visualization_msgs::Marker::POINTS;
            points.type = visualization_msgs::Marker::ARROW;
            // points.scale.x = 0.2;
            // points.scale.y = 0.2;
            points.scale.x = 0.7;
            points.scale.y = 0.1;
            points.scale.z = 0.1;
            points.color.g = 1.0f;
            points.color.a = 1.0;

            // std::cout <<  "iteration: " << i << ", drone " << drone->getId() << std::endl;
            auto start = std::chrono::high_resolution_clock::now();

            // if(i == 3 || i == 7){
            //     r_3->setLinearAcceleration(0, 0, 2);
            // }
            // else{
            //     r_3->setLinearAcceleration(0, 0, 0);
            // }
            // if(i == 40){
            if(i == 2){
                drone->setLinearAcceleration(0, 0, 0.2);
            }
            if(i == 80){
                drone->setLinearAcceleration(0, 0, -1);
            }
            if(i == 130){
                drone->setLinearAcceleration(0, 0, 0);
            }
            if(i >= 100){
                points.pose.orientation.x = 0.5;
                points.pose.orientation.y = 0.5;
                points.pose.orientation.z = 0.5;
            }

            // pro paralelizaci vyrobit v každé iteraci samostatný simulátor?
            rs->simulationTest(drone);

            geometry_msgs::Point p;
            // p.x = drone->getCurrentPosition().getX();
            // p.y = drone->getCurrentPosition().getY();
            // p.z = drone->getCurrentPosition().getZ();
            // points.points.push_back(p);
            points.pose.position.x = drone->getCurrentPosition().getX();
            points.pose.position.y = drone->getCurrentPosition().getY();
            points.pose.position.z = drone->getCurrentPosition().getZ();
            // points.pose.orientation.x = 0.0;

            marker_pub.publish(points);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> fp_ms = end - start;
            auto diff = (1000 * rs->getSimulationTime()) - fp_ms.count();
            unsigned int secs = diff > 0 ? (unsigned int)diff : 0;

            // std::cout << "diff: " << diff << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(secs));
            // std::cout << "slept for " << secs << " milliseconds." << std::endl;
        
        }

    }

    std::cout << "===== simulation ended =====" << std::endl;

    for(Robot *uav : uavs){
        delete uav;
    }

    delete rs;

    return 0;
}