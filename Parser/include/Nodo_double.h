#ifndef NODO_DOUBLE_H
#define NODO_DOUBLE_H
#include "Nodo.h"

class Nodo_double:public Nodo
{
    public:
        Nodo_double();
        
        Nodo_double(double a){this->valor=new double(a);};
        Nodo_double(std::string a);
        virtual ~Nodo_double();
        void get_valor(double*);
        void set_valor(double);
        double procesar();
        void obtener_variables();
        ////privado

        double * valor;
    protected:
    private:
        bool es_variable=false;
        std::string nom_var;
};

#endif // NODO_DOUBLE_H
