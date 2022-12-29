#include <iostream>

#include <chrono>
#include <thread>
#include <ctime>

#include <vector>
#include "robot.h"

#include "robot_simulator.h"
// #include <stdlib.h>
#include "boost/numeric/odeint.hpp"

using namespace std;
using namespace boost::numeric::odeint;

typedef runge_kutta_dopri5< double > stepper_type;

int main(){

    Robot* r_1 = new Robot(5, 5, 5);
    Robot* r_2 = new Robot(3, 2, 2);
    Robot* r_3 = new Robot();

    std::cout << r_1->getId() << std::endl;
    std::cout << r_2->getId() << std::endl;
    std::cout << r_3->getId() << std::endl;
    std::cout << "Number of robots: " << r_1->getNumberOfRobots() << std::endl;
    
    std::cout << r_1->getCurrentPosition().getX() << std::endl;
    r_1->getCurrentPosition().setX(-1);
    std::cout << r_1->getCurrentPosition().getX() << std::endl;

    RobotSimulator* rs = new RobotSimulator();

    r_3->setMaxHorizontalLinearVelocity(30);
    r_3->setMaxVerticalLinearVelocity(10);
    r_3->setMaxHorizontalLinearAcceleration(30);
    r_3->setMaxVerticalLinearAcceleration(10);
    r_3->setLinearVelocity(1, 2, 1);
    rs->setSimulationFrequency(10);

    r_3->printA();
    r_3->printV();
    r_3->printS();

    std::cout << "===== simulation started =====" << std::endl;

    for(int i = 0; i < 10; i++){

        std::cout << "iteration: " << i << std::endl;
        auto start = std::chrono::high_resolution_clock::now();

        if(i == 3 || i == 7){
            r_3->setLinearAcceleration(0, 0, 2);
        }
        else{
            r_3->setLinearAcceleration(0, 0, 0);
        }
        rs->simulationTest(r_3);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = end - start;
        auto diff = (1000 * rs->getSimulationTime()) - fp_ms.count();
        unsigned int secs = diff > 0 ? (unsigned int)diff : 0;

        std::cout << "diff: " << diff << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(secs));
        std::cout << "slept for " << secs << " milliseconds." << std::endl;

    }

    std::cout << "===== simulation ended =====" << std::endl;

    r_3->printA();
    r_3->printV();
    r_3->printS();
    
    
    delete r_1;
    delete r_2;
    delete r_3;
    delete rs;

    return 1;
}