#include <cmath>
#include "vector_t.h"

Vector::Vector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::~Vector() {}

double Vector::getX(){
    return this->x;
}

double Vector::getY(){
    return this->y;
}

double Vector::getZ(){
    return this->z;
}

double Vector::getVectorSize(){
    return Vector::vectorNorm(this->x, this->y, this->z);
}

void Vector::setX(double x){
    this->x = x;
}

void Vector::setY(double y){
    this->y = y;
}

void Vector::setZ(double z){
    this->z = z;
}

void Vector::setVectorCoordinates(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector::vectorNorm(double x, double y, double z){
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}