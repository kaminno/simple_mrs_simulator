#ifndef ROBOT_H
#define ROBOT_H

#include "vector_t.h"

class Robot{
    private:
        static unsigned int classId;
        unsigned int id;
        bool fly;
        Vector* currentPosition;
        Vector* currentLinearVelocity;
        Vector* currentAngularVelocity;
        Vector* currentLinearAcceleration;
        Vector* currentAngularAcceleration;
        double currentHeading;
        double maxHorizontalLinearVelocity;
        double maxVerticalLinearVelocity;
        double maxHorizontalLinearAcceleration;
        double maxVerticalLinearAcceleration;
        double maxAngularVelocity;
        double maxAngularAcceleration;
    public:
        Robot();
        Robot(double x, double y, double z);
        Robot(Vector s);
        Robot(double x, double y, double z, double v_x, double v_y, double v_z);
        Robot(Vector s, Vector v);
        ~Robot();
        unsigned int getId();
        unsigned int getNumberOfRobots();
        bool isAlive();
        Vector getCurrentPosition();
        Vector getCurrentLinearVelocity();
        Vector getCurrentAngularVelocity();
        Vector getCurrentLinearAcceleration();
        Vector getCurrentAngularAcceleration();
        double getCurrentHeading();
        double getMaxHorizontalLinearVelocity();
        double getMaxVerticalLinearVelocity();
        double getMaxHorizontalLinearAcceleration();
        double getMaxVerticalLinearAcceleration();
        // maybe let the set methods return vector size to easy check if we achieve its maximum or not
        void setAlive(bool alive);
        void setPosition(double x, double y, double z);
        void setPosition(Vector s);
        void setLinearVelocity(double v_x, double v_y, double v_z);
        void setLinearVelocity(Vector v);
        void setAngularVelocity(double v_x, double v_y, double v_z);
        void setAngularVelocity(Vector v);
        void setLinearAcceleration(double a_x, double a_y, double a_z);
        void setLinearAcceleration(Vector a);
        void setAngularAcceleration(double a_x, double a_y, double a_z);
        void setAngularAcceleration(Vector a);
        // where the angle 0 rad is pointing and if we counted right handed system or not
        void setHeading(double heading);
        void setMaxHorizontalLinearVelocity(double maxVelocity);
        void setMaxVerticalLinearVelocity(double maxVelocity);
        void setMaxHorizontalLinearAcceleration(double maxAcceleration);
        void setMaxVerticalLinearAcceleration(double maxAcceleration);

        void printS();
        void printV();
        void printA();
};

#endif
