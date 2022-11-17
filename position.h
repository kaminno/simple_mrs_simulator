class Position{
    private:
        double x;
        double y;
        double z;
    public:
        Position();
        Position(double x, double y, double z);
        ~Position();
        double getX();
        double getY();
        double getZ();
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setPosition(double x, double y, double z);
};
