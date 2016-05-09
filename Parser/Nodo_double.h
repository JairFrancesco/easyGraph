#ifndef NODO_DOUBLE_H
#define NODO_DOUBLE_H
#include "Nodo.h"

class Nodo_double:public Nodo
{
    public:
        Nodo_double();
        Nodo_double(double a){this->valor=new double(a);};
        virtual ~Nodo_double();
        void get_valor(double*);
        void set_valor(double);

        ////privado

        double * valor;
    protected:
    private:
};

#endif // NODO_DOUBLE_H
