#ifndef NODO_FUNCION_UNARIA_H
#define NODO_FUNCION_UNARIA_H
#include <Nodo.h>

class Nodo_funcion_unaria: public Nodo
{
    public:
        Nodo_funcion_unaria();
        Nodo_funcion_unaria(double(*funcion)(double)){this->valor=funcion;};
        void get_valor(double(*& funcion)(double));
        void set_valor(double(*& funcion)(double));
        virtual ~Nodo_funcion_unaria();


        ////privado
        double (*valor)(double);
    protected:
    private:
};

#endif // NODO_FUNCION_UNARIA_H
