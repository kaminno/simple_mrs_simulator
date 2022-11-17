class Velocity{
    private:
        double v_x;
        double v_y;
        double v_z;
        double vSize;
        double computeVSize();
    public:
        Velocity();
        Velocity(double v_x, double v_y, double v_z);
        ~Velocity();
        double getV_x();
        double getV_y();
        double getV_z();
        double getVSize();
        void setV_x(double v_x);
        void setV_y(double v_y);
        void setV_z(double v_z);
        void setVelocity(double v_x, double v_y, double v_z);
};
