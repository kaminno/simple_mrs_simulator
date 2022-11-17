#include "vector_t.h"

class Robot{
    private:
        static unsigned int classId;
        unsigned int id;
        Vector* currentPosition;
        Vector* currentLinearVelocity;
        Vector* currentAcceleration;
        double maxVelocity;
        double maxAcceleration;
        unsigned int heading;
    public:
        Robot();
        Robot(double x, double y, double z);
        Robot(double x, double y, double z, double v_x, double v_y, double v_z);
        ~Robot();
        unsigned int getId();
        unsigned int getNumberOfRobots();
        Vector getCurrentPosition();


        // Position* position = new Position(3, 3, 4);
};
