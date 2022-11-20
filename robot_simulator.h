#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include "robot.h"
#include "vector_t.h"

class RobotSimulator{
    private:
        float g;
        unsigned int sumulationFrequency;
        Vector updateVelocity(Robot robot);
        Vector updatePosition(Robot robot);
    public:
        RobotSimulator();
        RobotSimulator(float g, unsigned int frequency);
        ~RobotSimulator();
        void updateRobot(Robot robot, Vector a);
        void simulationTest();
};

#endif