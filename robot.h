#include "position.h"
#include "velocity.h"

class Robot{
    private:
        static unsigned int classId;
        unsigned int id;
        Position* current_position;
        Velocity* current_linear_velocity;
        // Acceleration* current_acceleration;
        // TODO add maximum velocity as constraint to not get infinite velocity
        unsigned int heading;
    public:
        Robot();
        Robot(double x, double y, double z);
        Robot(double x, double y, double z, double v_x, double v_y, double v_z);
        ~Robot();
        unsigned int getId();
        unsigned int getNumberOfRobots();


        // Position* position = new Position(3, 3, 4);
};
