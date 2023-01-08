#ifndef EQUATION_OF_MOTION_H
#define EQUATION_OF_MOTION_H

#include <cmath>
#include <vector>
#include "vector_t.h"

// typedef std::vector< double > state_type;

class EquationOfMotion{
    private:
        Vector* v;
        Vector* a;
        double omega;
        double alpha;
    public:
        EquationOfMotion() { this->v = new Vector(); this->a = new Vector(); }
        // ~LinearEquationOfMotion() { delete v; delete a; }
        void operator() (const std::vector< double >  &x, std::vector< double >  &dxdt, const double t){
            
            dxdt[4] = this->a->getX();
            dxdt[0] = this->v->getX() + this->a->getX()*t;

            dxdt[5] = this->a->getY();
            dxdt[1] = this->v->getY() + this->a->getY()*t;
            
            dxdt[6] = this->a->getZ();
            dxdt[2] = this->v->getZ() + this->a->getZ()*t;

            dxdt[7] = this->alpha;
            dxdt[3] = this->omega + this->alpha*t;

        }

        void setV(Vector v){
            this->v->setVectorCoordinates(v);
        }

        void setA(Vector a){
            this->a->setVectorCoordinates(a);
        }

        void setOmega(double o){
            this->omega = std::fmod(o, 2);
        }

        void setAlpha(double a){
            this->alpha = std::fmod(a, 2);
        }

        Vector* getV(){
            return this->v;
        }

        Vector* getA(){
            return this->a;
        }

        double getOmega(){
            return this->omega;
        }

        double getAlpha(){
            return this->alpha;
        }
};

#endif