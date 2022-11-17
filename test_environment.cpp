#include "robot.h"
#include <iostream>
// #include <stdlib.h>
#include <odeint.hpp>

int main(){

    Robot* r_1 = new Robot();
    Robot* r_2 = new Robot();
    Robot* r_3 = new Robot();
    // std::cout << robot->state->getX() << std::endl;
    std::cout << r_1->getId() << std::endl;
    std::cout << r_2->getId() << std::endl;
    std::cout << r_3->getId() << std::endl;
    std::cout << "Number of robots: " << r_1->getNumberOfRobots() << std::endl;
    delete r_1;
    delete r_2;
    delete r_3;

    return 1;
}