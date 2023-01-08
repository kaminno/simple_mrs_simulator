#ifndef VECTOR_T_H
#define VECTOR_T_H

class Vector{
    private:
        double x;
        double y;
        double z;
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(Vector* v);
        ~Vector();
        double getX();
        double getY();
        double getZ();
        Vector getVectorCoordinates();
        double getVectorSize();
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setVectorCoordinates(double x, double y, double z);
        void setVectorCoordinates(Vector v);
        static double vectorNorm(double x, double y, double z);
        static double vectorNorm(Vector v);
        // Vector operator*(double c){
        //     return Vector(this->x * c, this->y * c, this->z * c);
        // }
};

#endif
