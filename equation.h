#ifndef EQUATION_H
#define EQUATION_H

#include <vector>
#include "vector_t.h"

// typedef std::vector< double > state_type;

class Equation{
    private:
        Vector* v;
        Vector* a;
    public:
        Equation() { this->v = new Vector(); this->a = new Vector(); }
        // ~Equation() { delete v; delete a; }
        void operator() (const std::vector< double >  &x, std::vector< double >  &dxdt, const double t){
            
            dxdt[3] = this->a->getX();
            dxdt[0] = this->v->getX() + this->a->getX()*t;

            dxdt[4] = this->a->getY();
            dxdt[1] = this->v->getY() + this->a->getY()*t;
            
            dxdt[5] = this->a->getZ();
            dxdt[2] = this->v->getZ() + this->a->getZ()*t;

        }

        void setV(Vector v){
            this->v->setVectorCoordinates(v);
        }

        void setA(Vector a){
            this->a->setVectorCoordinates(a);
        }

        Vector* getV(){
            return this->v;
        }

        Vector* getA(){
            return this->a;
        }
};

#endif