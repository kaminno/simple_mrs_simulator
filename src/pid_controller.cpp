#include <iostream>

int main( int argc, char** argv ){

    // for(robot : robots){
    //     init prev_error
    //     init integral
    // }
    // maybe iterate only through incomming topics, not all uavs
    // while(true){
    //     for(robot : robots){
    //         error := setpoint − measured_value
    //         proportional := error;
    //         integral := integral + error × dt
    //         derivative := (error − previous_error) / dt
    //         output := Kp × proportional + Ki × integral + Kd × derivative
    //         previous_error := error
    //         wait(dt)
    //     }
    // }
    std::cout << "PID controller" << std::endl;
    return 0;
}