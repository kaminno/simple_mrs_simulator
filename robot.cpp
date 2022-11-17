#include <iostream>
#include "robot.h"

unsigned int Robot::classId = 0;

Robot::Robot()
: id(classId++), maxVelocity(1), maxAcceleration(1) {
    this->currentPosition = new Vector();
    this->currentLinearVelocity = new Vector();
    this->currentAcceleration = new Vector();
}

Robot::Robot(double x, double y, double z)
: Robot() {
    this->currentPosition->setVectorCoordinates(x, y, z);
}

Robot::Robot(double x, double y, double z, double v_x, double v_y, double v_z)
: Robot(x, y, z) {
    this->currentLinearVelocity->setVectorCoordinates(v_x, v_y, v_z);
}

Robot::~Robot(){
    delete currentPosition;
    delete currentLinearVelocity;
    delete currentAcceleration;
}

unsigned int Robot::getId(){
    return this->id;
}

unsigned int Robot::getNumberOfRobots(){
    return this->classId;
}

Vector Robot::getCurrentPosition(){
    return Vector(this->currentPosition->getX(), 2, 2);
}
