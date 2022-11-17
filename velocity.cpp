#include <cmath>
#include "velocity.h"

Velocity::Velocity() : v_x(0), v_y(0), v_z(0) {}

Velocity::Velocity(double v_x, double v_y, double v_z){
    this->v_x = v_x;
    this->v_y = v_y;
    this->v_z = v_z;
}

Velocity::~Velocity() {}

double Velocity::getV_x(){
    return this->v_x;
}

double Velocity::getV_y(){
    return this->v_y;
}

double Velocity::getV_z(){
    return this->v_z;
}

void Velocity::setV_x(double v_x){
    this->v_x = v_x;
}

void Velocity::setV_y(double v_y){
    this->v_y = v_y;
}

void Velocity::setV_z(double v_z){
    this->v_z = v_z;
}

void Velocity::setVelocity(double v_x, double v_y, double v_z){
    this->v_x = v_x;
    this->v_y = v_y;
    this->v_z = v_z;
}
