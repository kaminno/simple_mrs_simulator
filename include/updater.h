#ifndef UPDATER_H
#define UPDATER_H

#include <iostream>
#include "robot.h"
#include <vector>

class Updater{
    private:
        Robot* robot;
    public:
        Updater() : robot(nullptr) {}
        void operator() (const std::vector<double> &c_ , const double t){

            double v_x = c_[4];
            double v_y = c_[5];
            double v_z = c_[6];
            double v_o = c_[7];
            double s_x = c_[0];
            double s_y = c_[1];
            double s_z = c_[2];
            double heading = c_[3];

            this->robot->setLinearVelocity(v_x, v_y, v_z);
            this->robot->setAngularVelocity(v_o);
            this->robot->setPosition(s_x, s_y, s_z);
            this->robot->setHeading(heading);

        }

        void setRobot(Robot* robot){
            this->robot = robot;
        }
};

#endif