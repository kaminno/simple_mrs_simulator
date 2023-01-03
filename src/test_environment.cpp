#include <iostream>

#include <chrono>
#include <thread>
#include <ctime>

#include <vector>
#include "robot.h"

#include "robot_simulator.h"
// #include <stdlib.h>
#include "boost/numeric/odeint.hpp"

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

using namespace std;
using namespace boost::numeric::odeint;

typedef runge_kutta_dopri5< double > stepper_type;

int main( int argc, char** argv ){

    Robot* r_1 = new Robot(5, 5, 5);
    Robot* r_2 = new Robot(3, 2, 2);
    Robot* r_3 = new Robot();

    std::cout << r_1->getId() << std::endl;
    std::cout << r_2->getId() << std::endl;
    std::cout << r_3->getId() << std::endl;
    std::cout << "Number of robots: " << r_1->getNumberOfRobots() << std::endl;
    
    std::cout << r_1->getCurrentPosition().getX() << std::endl;
    r_1->getCurrentPosition().setX(-1);
    std::cout << r_1->getCurrentPosition().getX() << std::endl;

    RobotSimulator* rs = new RobotSimulator();

    r_3->setMaxHorizontalLinearVelocity(30);
    r_3->setMaxVerticalLinearVelocity(10);
    r_3->setMaxHorizontalLinearAcceleration(30);
    r_3->setMaxVerticalLinearAcceleration(10);
    r_3->setLinearVelocity(1, 2, 1);
    rs->setSimulationFrequency(10);

    r_3->printA();
    r_3->printV();
    r_3->printS();

    std::cout << "===== simulation started =====" << std::endl;

    ros::init(argc, argv, "simulation_test");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
    ros::Rate r(30);

    Robot* robots[2];
    robots[0] = r_1;
    robots[1] = r_2;

    for(int i = 0; i < 200; i++){
        for(Robot* drone : robots){
            visualization_msgs::Marker points;
            points.header.frame_id = "simulation";
            points.header.stamp = ros::Time::now();
            points.ns = "simulation_test";
            points.action = visualization_msgs::Marker::ADD;
            points.pose.orientation.w = 1.0;
            points.id = drone->getId();
            points.type = visualization_msgs::Marker::POINTS;
            points.scale.x = 0.2;
            points.scale.y = 0.2;
            points.color.g = 1.0f;
            points.color.a = 1.0;

            std::cout <<  "iteration: " << i << ", drone " << drone->getId() << std::endl;
            auto start = std::chrono::high_resolution_clock::now();

            // if(i == 3 || i == 7){
            //     r_3->setLinearAcceleration(0, 0, 2);
            // }
            // else{
            //     r_3->setLinearAcceleration(0, 0, 0);
            // }
            if(i == 40){
                drone->setLinearAcceleration(0, 0, 0.2);
            }
            if(i == 80){
                drone->setLinearAcceleration(0, 0, -1);
            }
            if(i == 130){
                drone->setLinearAcceleration(0, 0, 0);
            }

            // pro paralelizaci vyrobit v každé iteraci samostatný simulátor?
            rs->simulationTest(drone);

            geometry_msgs::Point p;
            p.x = drone->getCurrentPosition().getX();
            p.y = drone->getCurrentPosition().getY();;
            p.z = drone->getCurrentPosition().getZ();;
            points.points.push_back(p);
            marker_pub.publish(points);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> fp_ms = end - start;
            auto diff = (1000 * rs->getSimulationTime()) - fp_ms.count();
            unsigned int secs = diff > 0 ? (unsigned int)diff : 0;

            std::cout << "diff: " << diff << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(secs));
            std::cout << "slept for " << secs << " milliseconds." << std::endl;
        
        }


        // std::cout << "iteration: " << i << std::endl;
        // auto start = std::chrono::high_resolution_clock::now();

        // // if(i == 3 || i == 7){
        // //     r_3->setLinearAcceleration(0, 0, 2);
        // // }
        // // else{
        // //     r_3->setLinearAcceleration(0, 0, 0);
        // // }
        // if(i == 40){
        //     r_3->setLinearAcceleration(0, 0, 0.2);
        // }
        // if(i == 80){
        //     r_3->setLinearAcceleration(0, 0, -1);
        // }
        // if(i == 130){
        //     r_3->setLinearAcceleration(0, 0, 0);
        // }

        // rs->simulationTest(r_3);

        // geometry_msgs::Point p;
        // p.x = r_3->getCurrentPosition().getX();
        // p.y = r_3->getCurrentPosition().getY();;
        // p.z = r_3->getCurrentPosition().getZ();;
        // points.points.push_back(p);
        // marker_pub.publish(points);

        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double, std::milli> fp_ms = end - start;
        // auto diff = (1000 * rs->getSimulationTime()) - fp_ms.count();
        // unsigned int secs = diff > 0 ? (unsigned int)diff : 0;

        // std::cout << "diff: " << diff << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(secs));
        // std::cout << "slept for " << secs << " milliseconds." << std::endl;

    }

    std::cout << "===== simulation ended =====" << std::endl;

    r_3->printA();
    r_3->printV();
    r_3->printS();
    
    r_3->setLinearVelocity(-20, 40, -30);
    r_3->printV();
    
    delete r_1;
    delete r_2;
    delete r_3;
    delete rs;

    return 1;
}