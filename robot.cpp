#include <iostream>
#include "robot.h"

unsigned int Robot::classId = 0;

Robot::Robot()
: id(classId++), alive(true), currentHeading(0), maxHorizontalLinearVelocity(1),
    maxVerticalLinearVelocity(1), maxHorizontalLinearAcceleration(1), maxVerticalLinearAcceleration(1) {
    this->currentPosition = new Vector();
    // this->currentPosition->setZ(1);
    this->currentLinearVelocity = new Vector();
    this->currentAngularVelocity = new Vector();
    this->currentLinearAcceleration = new Vector();
    this->currentAngularAcceleration = new Vector();
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
    delete this->currentPosition;
    delete this->currentLinearVelocity;
    delete this->currentAngularVelocity;
    delete this->currentLinearAcceleration;
    delete this->currentAngularAcceleration;
}

unsigned int Robot::getId(){
    return this->id;
}

unsigned int Robot::getNumberOfRobots(){
    return this->classId;
}

bool Robot::isAlive(){
    return this->alive;
}

Vector Robot::getCurrentPosition(){
    return this->currentPosition->getVectorCoordinates();
}

Vector Robot::getCurrentLinearVelocity(){
    return this->currentLinearVelocity->getVectorCoordinates();
}

Vector Robot::getCurrentAngularVelocity(){
    return this->currentAngularVelocity->getVectorCoordinates();
}

Vector Robot::getCurrentLinearAcceleration(){
    return this->currentLinearAcceleration->getVectorCoordinates();
}

Vector Robot::getCurrentAngularAcceleration(){
    return this->currentAngularAcceleration->getVectorCoordinates();
}

double Robot::getCurrentHeading(){
    return this->currentHeading;
}

double Robot::getMaxHorizontalLinearVelocity(){
    return this->maxHorizontalLinearVelocity;
}

double Robot::getMaxVerticalLinearVelocity(){
    return this->maxVerticalLinearVelocity;
}

double Robot::getMaxHorizontalLinearAcceleration(){
    return this->maxHorizontalLinearAcceleration;
}

double Robot::getMaxVerticalLinearAcceleration(){
    return this->maxVerticalLinearAcceleration;
}

void Robot::setAlive(bool alive){
    this->alive = alive;
}

void Robot::setPosition(double x, double y, double z){
    if(this->alive){
        if(z < 0){
            z = -1;
            this->alive = false;
            std::cerr << "Dron " << this->id << " crashed!" << std::endl;
        }
        this->currentPosition->setVectorCoordinates(x, y, z);
    }
}

void Robot::setPosition(Vector s){
    // this->currentPosition->setVectorCoordinates(s);
    double s_x = this->currentPosition->getX();
    double s_y = this->currentPosition->getY();
    double s_z = this->currentPosition->getZ();
    this->setPosition(s_x, s_y, s_z);
}

void Robot::setLinearVelocity(double v_x, double v_y, double v_z){
    if(this->alive){
        // double newVelocitySize = Vector::vectorNorm(v_x, v_y, v_z);
        double horizontalSize = Vector::vectorNorm(v_x, v_y, 0);
        double verticalSize = Vector::vectorNorm(0, 0, v_z);
        // if(newVelocitySize <= this->maxVelocity){
        //     this->currentLinearVelocity->setVectorCoordinates(v_x, v_y, v_z);
        // }
        double vx = horizontalSize <= this->maxHorizontalLinearVelocity ? v_x : this->currentLinearVelocity->getX();
        double vy = horizontalSize <= this->maxHorizontalLinearVelocity ? v_y : this->currentLinearVelocity->getY();
        double vz = verticalSize <= this->maxVerticalLinearVelocity ? v_z : this->currentLinearVelocity->getZ();
        this->currentLinearVelocity->setVectorCoordinates(vx, vy, vz);
    }
}

void Robot::setLinearVelocity(Vector v){
    // double newVelocitySize = Vector::vectorNorm(v);
    // if(newVelocitySize <= this->maxVelocity){
    //     this->currentLinearVelocity->setVectorCoordinates(v);
    // }
    double v_x = v.getVectorCoordinates().getX();
    double v_y = v.getVectorCoordinates().getY();
    double v_z = v.getVectorCoordinates().getZ();
    this->setLinearVelocity(v_x, v_y, v_z);
}

void Robot::setAngularVelocity(double v_x, double v_y, double v_z){
    // also recompute the heading

    // TODO - check it
    // double horizontalSize = Vector::vectorNorm(v_x, v_y, 0);
    // double verticalSize = Vector::vectorNorm(0, 0, v_z);
    // double vx = horizontalSize <= this->maxHorizontalLinearVelocity ? v_x : this->currentLinearVelocity->getX();
    // double vy = horizontalSize <= this->maxHorizontalLinearVelocity ? v_y : this->currentLinearVelocity->getY();
    // double vz = verticalSize <= this->maxVerticalLinearVelocity ? v_z : this->currentLinearVelocity->getZ();
    // this->currentLinearVelocity->setVectorCoordinates(vx, vy, vz);
    std::cerr << "Robot::setAngularVelocity() has to be implemented!" << std::endl;
}

void Robot::setAngularVelocity(Vector v){
    // also recompute the heading
    std::cerr << "Robot::setAngularVelocity() has to be implemented!" << std::endl;
}

void Robot::setLinearAcceleration(double a_x, double a_y, double a_z){
    if(this->alive){
        double horizontalSize = Vector::vectorNorm(a_x, a_y, 0);
        double verticalSize = Vector::vectorNorm(0, 0, a_z);
        double ax = horizontalSize <= this->maxHorizontalLinearAcceleration ? a_x : this->currentLinearAcceleration->getX();
        double ay = horizontalSize <= this->maxHorizontalLinearAcceleration ? a_y : this->currentLinearAcceleration->getY();
        double az = verticalSize <= this->maxVerticalLinearAcceleration ? a_z : this->currentLinearAcceleration->getZ();
        this->currentLinearAcceleration->setVectorCoordinates(ax, ay, az);
    }
}

void Robot::setLinearAcceleration(Vector a){
    double a_x = a.getVectorCoordinates().getX();
    double a_y = a.getVectorCoordinates().getY();
    double a_z = a.getVectorCoordinates().getZ();
    this->setLinearAcceleration(a_x, a_y, a_z);
}

void Robot::setAngularAcceleration(double v_x, double v_y, double v_z){
    std::cerr << "Robot::setAngularAcceleration() has to be implemented!" << std::endl;
}

void Robot::setAngularAcceleration(Vector v){
    std::cerr << "Robot::setAngularAcceleration() has to be implemented!" << std::endl;
}

void Robot::setHeading(double heading){
    // make sure that new heading is in correct range <0, 2pi)
    if(this->alive){
        this->currentHeading = heading;
    }
}

void Robot::setMaxHorizontalLinearVelocity(double maxVelocity){
    if(maxVelocity >= 0){
        this->maxHorizontalLinearVelocity = maxVelocity;
    }
}

void Robot::setMaxVerticalLinearVelocity(double maxVelocity){
    if(maxVelocity >= 0){
        this->maxVerticalLinearVelocity = maxVelocity;
    }
}

void Robot::setMaxHorizontalLinearAcceleration(double maxAcceleration){
    if(maxAcceleration >= 0){
        this->maxHorizontalLinearAcceleration = maxAcceleration;
    }
}

void Robot::setMaxVerticalLinearAcceleration(double maxAcceleration){
    if(maxAcceleration >= 0){
        this->maxVerticalLinearAcceleration = maxAcceleration;
    }
}

void Robot::printS(){
    std::cout << "s = (" << this->currentPosition->getX() << ", " << this->currentPosition->getY() << ", " << this->currentPosition->getZ() << ")" << std::endl;
}

void Robot::printV(){
    std::cout << "v = (" << this->currentLinearVelocity->getX() << ", " << this->currentLinearVelocity->getY() << ", " << this->currentLinearVelocity->getZ() << ")" << std::endl;
}

void Robot::printA(){
    std::cout << "a = (" << this->currentLinearAcceleration->getX() << ", " << this->currentLinearAcceleration->getY() << ", " << this->currentLinearAcceleration->getZ() << ")" << std::endl;
}
