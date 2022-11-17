#include "position.h"

Position::Position(){}

Position::Position(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Position::~Position() {}

double Position::getX(){
    return this->x;
}

double Position::getY(){
    return this->y;
}

double Position::getZ(){
    return this->z;
}

void Position::setX(double x){
    this->x = x;
}

void Position::setY(double y){
    this->y = y;
}

void Position::setZ(double z){
    this->z = z;
}

void Position::setPosition(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
