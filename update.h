#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include "robot.h"
#include <vector>

class Upd{
    private:
        Robot* robot;
    public:
        Upd() : robot(nullptr) {}
        void operator() (const std::vector<double> &c_ , const double t){

            double v_x = c_[3];
            double v_y = c_[4];
            double v_z = c_[5];
            double s_x = c_[0];
            double s_y = c_[1];
            double s_z = c_[2];

            this->robot->setLinearVelocity(v_x, v_y, v_z);
            this->robot->setPosition(s_x, s_y, s_z);

        }

        void setRobot(Robot* robot){
            this->robot = robot;
        }
};

#endif