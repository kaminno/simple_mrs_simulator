class Vector{
    private:
        double x;
        double y;
        double z;
    public:
        Vector(double x = 0, double y = 0, double z = 0);
        ~Vector();
        double getX();
        double getY();
        double getZ();
        double getVectorSize();
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setVectorCoordinates(double x, double y, double z);
        static double vectorNorm(double x, double y, double z);
};
