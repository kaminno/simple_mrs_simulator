#include "robot_simulator.h"
#include "vector_t.h"

#include "boost/numeric/odeint.hpp"
using namespace boost::numeric::odeint;

RobotSimulator::RobotSimulator()
: g(9.81), sumulationFrequency(1000) {};

RobotSimulator::RobotSimulator(float g, unsigned int frequency){};
RobotSimulator::~RobotSimulator(){};

Vector RobotSimulator::updateVelocity(Robot robot){

    void velocityEquation(double x, double &dxdt, double t){
        dxdt = 2;
    }
}

// void RobotSimulator::updatePosition(Robot robot, Vector a){
//     robot.setAcceleration(a);

// }

void position(double x, double &dxdt, double t){
        dxdt = 0;
    }
void write_cout_( const double &x , const double t )
{
    std::cout << t << '\t' << x << std::endl;
}
void RobotSimulator::simulationTest(){
    double x = 0.0;
    typedef runge_kutta_dopri5< double > stepper_type;
    
    double res = integrate_adaptive(make_controlled( 1E-12 , 1E-12 , stepper_type() ), position, x, 0.0, 1.0, 0.01, write_cout_);
    std::cout << "result: " << res << std::endl;
}
