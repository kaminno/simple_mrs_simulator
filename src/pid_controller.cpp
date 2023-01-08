#include <iostream>
#include <vector>

#include <ros/ros.h>
#include <ros/node_handle.h>
#include "mrs_msgs/Reference.h"

int main( int argc, char** argv ){

    ros::init(argc, argv, "pid_controller");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    ros::Publisher uav0_pub = nh.advertise<mrs_msgs::Reference>("/uav0/acceleration", 100);
    ros::Publisher uav1_pub = nh.advertise<mrs_msgs::Reference>("/uav1/acceleration", 100);


    // for(robot : robots){
    //     init prev_error
    //     init integral
    // }
    // maybe iterate only through incomming topics, not all uavs
    // while(true){
    //     for(robot : robots){
    //         error := setpoint − measured_value
    //         proportional := error;
    //         integral := integral + error × dt
    //         derivative := (error − previous_error) / dt
    //         output := Kp × proportional + Ki × integral + Kd × derivative
    //         previous_error := error
    //         wait(dt)
    //     }
    // }

    double previous_error = 0;
    double integral = 0;
    double setpoint = 50;
    double error = setpoint;
    double measured_value = 0;
    double dt = 0.1;
    double Kp = 0.1;
    double Ki = 1;
    double Kd = 0.01;
    // while(abs(error) > 0.01){
    //     std::cout << "current error: " << error << std::endl;
    //     std::cout << "measured value: " << measured_value << std::endl;
    //     error = setpoint - measured_value;
    //     double proportional = error;
    //     std::cout << "proportional: " << proportional << std::endl;
    //     integral = integral + error * dt;
    //     std::cout << "integral: " << integral << std::endl;
    //     double derivative = (error - previous_error) / dt;
    //     std::cout << "derivative: " << derivative << std::endl;
    //     double output = Kp * proportional + Ki * integral + Kd * derivative;
    //     previous_error = error;
    //     measured_value = output;
    //     std::cout << "next error: " << error << std::endl;
    //     std::cout << "----------------------------" << std::endl;
    // }

    // void handle_reference(){
    //     compute_pid
    //     publish_on_any_topic_name
    // }
    // general_subscriber(any_topic_name, handle_reference)
    // while(ros::ok()){
        
    //     ros::spin();
    // }
    
    
    int q = 0;
    std::cout << "PID controller starts" << std::endl;
    while(ros::ok()){
        mrs_msgs::Reference ref;
        // ref.heading = 0;
        if(q > 20){
            ref.heading = 0.7;
            ref.position.x = 0.5;
            ref.position.y = 0;
            ref.position.z = 0.8;
        }
        else{
            ref.heading = -0.3;
            ref.position.x = -0.1;
            ref.position.y = 0.5;
            ref.position.z = -0.2;
        }
        std::cout << "before pub" << std::endl;
        uav0_pub.publish(ref);
        uav1_pub.publish(ref);
        std::cout << "after pub" << std::endl;
        q++;
        std::cout << "after spin" << std::endl;
        rate.sleep();
    }
    std::cout << "PID controller ends" << std::endl;
    return 0;
}