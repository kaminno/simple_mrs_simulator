#include "robot_simulator.h"
#include "vector_t.h"
// #include "velocityEquation.h"
// #include "updater.h"
#include "update.h"
#include "equation.h"

#include "boost/numeric/odeint.hpp"
using namespace boost::numeric::odeint;

RobotSimulator::RobotSimulator()
: g(9.81), currentRobot(nullptr) {
    // this->ve = new VelocityEquation();
    // this->pe = new PositionEquation();
    // this->upd = new Updater();
    this->eq = new Equation();
    this->up = new Upd();
    this->setSimulationFrequency(1);
    this->setNumberOfSteps(10);
};

// RobotSimulator::RobotSimulator(float g){};
RobotSimulator::~RobotSimulator(){
    delete this->eq->getV();
    delete this->eq->getA();
    delete this->eq;
    delete this->up;
};

// void RobotSimulator::computeLinearVelocity(){
//     this->upd->setType(SimulationType::accToVel);
//     typedef runge_kutta_dopri5< double > stepper_type;

//     double x = this->currentRobot->getCurrentLinearVelocity().getX();
//     this->ve->setA(this->currentRobot->getCurrentLinearAcceleration().getX());
//     this->upd->setCoordinate(Coordinate::x);
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->ve, x, 0.0, this->simulationFrequency, this->stepSize, *this->upd);
    
//     double y = this->currentRobot->getCurrentLinearVelocity().getY();
//     this->ve->setA(this->currentRobot->getCurrentLinearAcceleration().getY());
//     this->upd->setCoordinate(Coordinate::y);
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->ve, y, 0.0, this->simulationFrequency, this->stepSize, *this->upd);

//     double z = this->currentRobot->getCurrentLinearVelocity().getZ();
//     this->ve->setA(this->currentRobot->getCurrentLinearAcceleration().getZ());
//     this->ve->setG(this->g);
//     this->upd->setCoordinate(Coordinate::z);
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->ve, z, 0.0, this->simulationFrequency, this->stepSize, *this->upd);
//     this->ve->setG(0);

//     std::cout << "--------------------" << std::endl;
// }

// void RobotSimulator::computePosition(){
//     this->computeLinearVelocity();

//     this->upd->setType(SimulationType::velToPos);
//     typedef runge_kutta_dopri5< double > stepper_type;

//     // std::cout << "1" << std::endl;
//     double x = this->currentRobot->getCurrentPosition().getX();
//     // std::cout << "1.1" << std::endl;
//     this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getX());
//     // std::cout << "1.2" << std::endl;
//     this->upd->setCoordinate(Coordinate::x);
//     // std::cout << "1.3" << std::endl;
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->pe, x, 0.0, this->simulationFrequency, this->stepSize, *this->upd);
    
//     // std::cout << "2" << std::endl;
//     double y = this->currentRobot->getCurrentPosition().getY();
//     this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getY());
//     this->upd->setCoordinate(Coordinate::y);
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->pe, y, 0.0, this->simulationFrequency, this->stepSize, *this->upd);

//     double z = this->currentRobot->getCurrentPosition().getZ();
//     this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getZ());
//     this->upd->setCoordinate(Coordinate::z);
//     integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
//                  *this->pe, z, 0.0, this->simulationFrequency, this->stepSize, *this->upd);
                 
//     std::cout << "--------------------" << std::endl;
// }

void RobotSimulator::computeBoth(){
    // this->computeLinearVelocity();

    // this->upd->setType(SimulationType::velToPos);
    // typedef runge_kutta_dopri5< double > stepper_type;

    // // std::cout << "1" << std::endl;
    // double x = this->currentRobot->getCurrentPosition().getX();
    // // std::cout << "1.1" << std::endl;
    // this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getX());
    // // std::cout << "1.2" << std::endl;
    // this->upd->setCoordinate(Coordinate::x);
    // // std::cout << "1.3" << std::endl;
    // integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
    //              *this->pe, x, 0.0, this->simulationFrequency, this->stepSize, *this->upd);
    
    // // std::cout << "2" << std::endl;
    // double y = this->currentRobot->getCurrentPosition().getY();
    // this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getY());
    // this->upd->setCoordinate(Coordinate::y);
    // integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
    //              *this->pe, y, 0.0, this->simulationFrequency, this->stepSize, *this->upd);

    // double z = this->currentRobot->getCurrentPosition().getZ();
    // this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getZ());
    // this->upd->setCoordinate(Coordinate::z);
    // integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
    //              *this->pe, z, 0.0, this->simulationFrequency, this->stepSize, *this->upd);

    // double z = this->currentRobot->getCurrentPosition().getZ();
    // this->pe->setV(this->currentRobot->getCurrentLinearVelocity().getZ());
    // this->upd->setCoordinate(Coordinate::z);
    std::vector<double> s(6);
    s[0] = this->currentRobot->getCurrentPosition().getX();
    s[1] = this->currentRobot->getCurrentPosition().getY();
    s[2] = this->currentRobot->getCurrentPosition().getZ();
    s[3] = this->currentRobot->getCurrentLinearVelocity().getX();
    s[4] = this->currentRobot->getCurrentLinearVelocity().getY();
    s[5] = this->currentRobot->getCurrentLinearVelocity().getZ();
    // integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ),
    //              *this->eq, s, 0.0, this->simulationFrequency, this->stepSize, *this->up);
    this->eq->setA(this->currentRobot->getCurrentLinearAcceleration());
    this->eq->setV(this->currentRobot->getCurrentLinearVelocity());
    integrate(*this->eq, s, 0.0, this->simulationTime, this->stepSize, *this->up);
                 
    std::cout << "--------------------" << std::endl;
}

void RobotSimulator::simulationTest(Robot* robot){
    this->currentRobot = robot;
    // this->upd->setRobot(this->currentRobot);

    this->up->setRobot(this->currentRobot);

    std::cout << "stats before simulation step: " << std::endl;
    this->currentRobot->printS();
    this->currentRobot->printV();
    this->currentRobot->printA();

    // this->computeLinearVelocity();
    // this->computePosition();
    this->computeBoth();
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
