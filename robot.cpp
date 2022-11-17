#include "robot.h"
// #include "position.h"
// #include "velocity.h"

#include <iostream>
unsigned int Robot::classId = 0;

Robot::Robot()
: id(classId++) {}

Robot::Robot(double x, double y, double z)
: Robot() {
    this->current_position = new Position(x, y, z);
    this->current_linear_velocity = new Velocity();
}

Robot::Robot(double x, double y, double z, double v_x, double v_y, double v_z)
: Robot(x, y, z) {
    this->current_linear_velocity->setVelocity(v_x, v_y, v_z);
}

Robot::~Robot(){
    if(this->current_position){
        delete current_position;
    }
    if(this->current_linear_velocity){
        delete current_linear_velocity;
    }
    // if(this->current_acceleration){
    //     delete current_acceleration;
    // }
}

unsigned int Robot::getId(){
    return this->id;
}

unsigned int Robot::getNumberOfRobots(){
    return this->classId;
}