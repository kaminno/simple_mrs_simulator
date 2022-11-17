#include <iostream>
#include "robot.h"

// #include <stdlib.h>
#include "boost/numeric/odeint.hpp"

using namespace std;
using namespace boost::numeric::odeint;


/* we solve the simple ODE x' = 3/(2t^2) + x/(2t)
 * with initial condition x(1) = 0.
 * Analytic solution is x(t) = sqrt(t) - 1/t
 */

void rhs( const double x , double &dxdt , const double t )
{
    // dxdt = 3.0/(2.0*t*t) + x/(2.0*t);
    dxdt = x*t;
}

void write_cout( const double &x , const double t )
{
    cout << t << '\t' << x << endl;
}

// state_type = double
typedef runge_kutta_dopri5< double > stepper_type;

int main(){

    Robot* r_1 = new Robot();
    Robot* r_2 = new Robot(3, 2, 2);
    Robot* r_3 = new Robot();
    // std::cout << robot->state->getX() << std::endl;
    std::cout << r_1->getId() << std::endl;
    std::cout << r_2->getId() << std::endl;
    std::cout << r_3->getId() << std::endl;
    std::cout << "Number of robots: " << r_1->getNumberOfRobots() << std::endl;
    

    // std::cout << vectorNorm(3, 4, 0) << std::endl;
    std::cout << r_1->getCurrentPosition().getX() << std::endl;

    double x = 0.0;
    integrate_adaptive( make_controlled( 1E-12 , 1E-12 , stepper_type() ) ,
                        rhs , x , 1.0 , 10.0 , 0.1 , write_cout );

    delete r_1;
    delete r_2;
    delete r_3;

    return 1;
}