#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include "robot.h"
#include "vector_t.h"
// #include "velocityEquation.h"
// #include "position_equation.h"
// #include "updater.h"
#include "update.h"
#include "equation.h"

const double ZERO = 1e-3;

class RobotSimulator{
    private:
        float g;
        double simulationFrequency;
        double simulationTime;
        double stepSize;
        unsigned int numberOfSteps;
        Robot* currentRobot;
        // VelocityEquation* ve;
        // PositionEquation* pe;
        Equation* eq;
        // Updater* upd;
        Upd* up;
        // void computeLinearVelocity();
        // void computePosition();
        void computeBoth();
    public:
        RobotSimulator();
        // RobotSimulator(float g);//, unsigned int frequency);
        ~RobotSimulator();

        void updateRobotState(Robot robot);
        void simulationTest(Robot* robot);
        void setSimulationFrequency(double freq);
        // void setSimulationTime(double time);
        // void setStepSize(double step);
        void setNumberOfSteps(unsigned int num);
        double getSimulationFrequency();
        double getSimulationTime();
        double getStepSize();
        double getNumberOfSteps();
        Equation* getEquation() {return this->eq;}
};

#endif