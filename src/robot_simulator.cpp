#include "../include/robot_simulator.h"
#include "../include/vector_t.h"
// #include "velocityEquation.h"
// #include "updater.h"
#include "../include/updater.h"
#include "../include/equation_of_motion.h"

#include "boost/numeric/odeint.hpp"
using namespace boost::numeric::odeint;

RobotSimulator::RobotSimulator()
: g(9.81), currentRobot(nullptr) {
    // this->ve = new VelocityEquation();
    // this->pe = new PositionEquation();
    // this->upd = new Updater();
    this->equationOfMotion = new EquationOfMotion();
    this->up = new Updater();
    this->setSimulationFrequency(1);
    this->setNumberOfSteps(10);
};

// RobotSimulator::RobotSimulator(float g){};
RobotSimulator::~RobotSimulator(){
    delete this->equationOfMotion->getV();
    delete this->equationOfMotion->getA();
    delete this->equationOfMotion;
    delete this->up;
};

void RobotSimulator::computeNewState(){
    
    std::vector<double> s(8);
    s[0] = this->currentRobot->getCurrentPosition().getX();
    s[1] = this->currentRobot->getCurrentPosition().getY();
    s[2] = this->currentRobot->getCurrentPosition().getZ();
    s[3] = this->currentRobot->getCurrentHeading();
    s[4] = this->currentRobot->getCurrentLinearVelocity().getX();
    s[5] = this->currentRobot->getCurrentLinearVelocity().getY();
    s[6] = this->currentRobot->getCurrentLinearVelocity().getZ();
    s[7] = this->currentRobot->getCurrentAngularVelocity();
    // integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
    //              *this->equationOfMotion, s, 0.0, this->simulationFrequency, this->stepSize, *this->up);
    this->equationOfMotion->setA(this->currentRobot->getCurrentLinearAcceleration());
    this->equationOfMotion->setV(this->currentRobot->getCurrentLinearVelocity());
    this->equationOfMotion->setAlpha(this->currentRobot->getCurrentAngularAcceleration());
    this->equationOfMotion->setOmega(this->currentRobot->getCurrentAngularVelocity());
    integrate(*this->equationOfMotion, s, 0.0, this->simulationTime, this->stepSize, *this->up);
                 
    // std::cout << "--------------------" << std::endl;
}

void RobotSimulator::simulationTest(Robot* robot){
    this->currentRobot = robot;
    // this->upd->setRobot(this->currentRobot);

    this->up->setRobot(this->currentRobot);

    // std::cout << "stats before simulation step: " << std::endl;
    // this->currentRobot->printS();
    // this->currentRobot->printV();
    // this->currentRobot->printA();

    // this->computeLinearVelocity();
    // this->computePosition();
    this->computeNewState();
}

void RobotSimulator::setSimulationFrequency(double freq){
    if(freq > 0){
        this->simulationFrequency = freq;
        this->simulationTime = 1 / freq;
    }
}

void RobotSimulator::setNumberOfSteps(unsigned int num){
    if(num > 0){
        this->numberOfSteps = num;
        this->stepSize = this->simulationTime / num;
    }
}

// void RobotSimulator::setStepSize(double step){
//     if(step > 0){
//         this->stepSize = step;
//     }
// }

double RobotSimulator::getSimulationFrequency(){
    return this->simulationFrequency;
}

double RobotSimulator::getSimulationTime(){
    return this->simulationTime;
}

double RobotSimulator::getStepSize(){
    return this->stepSize;
}

double RobotSimulator::getNumberOfSteps(){
    return this->numberOfSteps;
}
