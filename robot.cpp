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

Robot::Robot(Vector s)
: Robot() {
    this->currentPosition->setVectorCoordinates(s);
}

Robot::Robot(double x, double y, double z, double v_x, double v_y, double v_z)
: Robot(x, y, z) {
    this->currentLinearVelocity->setVectorCoordinates(v_x, v_y, v_z);
}

Robot::Robot(Vector s, Vector v)
: Robot(s) {
    this->currentLinearVelocity->setVectorCoordinates(v);
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
    return this->currentPosition->getVectorCoordinates();
    // double x = this->currentPosition->getX();
    // double y = this->currentPosition->getY();
    // double z = this->currentPosition->getZ();
    // return Vector(x, y, z);
}

Vector Robot::getCurrentLinearVelocity(){
    return this->currentLinearVelocity->getVectorCoordinates();
    // double v_x = this->currentLinearVelocity->getX();
    // double v_y = this->currentLinearVelocity->getY();
    // double v_z = this->currentLinearVelocity->getZ();
    // return Vector(v_x, v_y, v_z);
}

Vector Robot::getCurrentAcceleration(){
    return this->currentAcceleration->getVectorCoordinates();
    // double a_x = this->currentAcceleration->getX();
    // double a_y = this->currentAcceleration->getY();
    // double a_z = this->currentAcceleration->getZ();
    // return Vector(a_x, a_y, a_z);
}

double Robot::getMaxVelocity(){
    return this->maxVelocity;
}

double Robot::getMaxAcceleration(){
    return this->maxAcceleration;
}

double Robot::getCurrentHeading(){
    return this->currentHeading;
}

void Robot::setPosition(double x, double y, double z){
    this->currentPosition->setVectorCoordinates(x, y, z);
}

void Robot::setPosition(Vector s){
    this->currentPosition->setVectorCoordinates(s);
}

void Robot::setVelocity(double v_x, double v_y, double v_z){
    double newVelocitySize = Vector::vectorNorm(v_x, v_y, v_z);
    if(newVelocitySize <= this->maxVelocity){
        this->currentLinearVelocity->setVectorCoordinates(v_x, v_y, v_z);
    }
}

void Robot::setVelocity(Vector v){
    double newVelocitySize = Vector::vectorNorm(v);
    if(newVelocitySize <= this->maxVelocity){
        this->currentLinearVelocity->setVectorCoordinates(v);
    }
}

void Robot::setAcceleration(double a_x, double a_y, double a_z){
    double newAccelerationSize = Vector::vectorNorm(a_x, a_y, a_z);
    if(newAccelerationSize <= this->maxAcceleration){
        this->currentAcceleration->setVectorCoordinates(a_x, a_y, a_z);
    }
}

void Robot::setAcceleration(Vector a){
    double newAccelerationSize = Vector::vectorNorm(a);
    if(newAccelerationSize <= this->maxAcceleration){
        this->currentAcceleration->setVectorCoordinates(a);
    }
}

void Robot::setHeading(double heading){
    // make sure that new heading is in correct range <0, 2pi)
    this->currentHeading = heading;
}

void Robot::setMaxVelocity(double maxVelocity){
    if(maxVelocity >= 0){
        this->maxVelocity = maxVelocity;
    }
}

void Robot::setMaxAcceleration(double maxAcceleration){
    if(maxAcceleration >= 0){
        this->maxAcceleration = maxAcceleration;
    }
}
