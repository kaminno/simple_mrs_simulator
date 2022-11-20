#ifndef ROBOT_H
#define ROBOT_H

#include "vector_t.h"

class Robot{
    private:
        static unsigned int classId;
        unsigned int id;
        Vector* currentPosition;
        Vector* currentLinearVelocity;
        Vector* currentAcceleration;
        double currentHeading;
        double maxVelocity;
        double maxAcceleration;
    public:
        Robot();
        Robot(double x, double y, double z);
        Robot(Vector s);
        Robot(double x, double y, double z, double v_x, double v_y, double v_z);
        Robot(Vector s, Vector v);
        ~Robot();
        unsigned int getId();
        unsigned int getNumberOfRobots();
        Vector getCurrentPosition();
        Vector getCurrentLinearVelocity();
        Vector getCurrentAcceleration();
        double getCurrentHeading();
        double getMaxVelocity();
        double getMaxAcceleration();
        // maybe let the set methods return vector size to easy check if we achieve its maximum or not
        void setPosition(double x, double y, double z);
        void setPosition(Vector s);
        void setVelocity(double v_x, double v_y, double v_z);
        void setVelocity(Vector v);
        void setAcceleration(double a_x, double a_y, double a_z);
        void setAcceleration(Vector a);
        // where the angle 0 rad is pointing and if we counted right handed system or not
        void setHeading(double heading);
        void setMaxVelocity(double maxVelocity);
        void setMaxAcceleration(double maxAcceleration);
};

#endif
