#ifndef NODO_FUNCION_BINARIA_H
#define NODO_FUNCION_BINARIA_H
#include <Nodo.h>



class Nodo_funcion_binaria: public Nodo
{
    public:
        Nodo_funcion_binaria();
        Nodo_funcion_binaria(double(*funcion)(double, double)){this->valor=funcion;};
        void get_valor(double(*& funcion)(double, double));
        void set_valor(double(*& funcion)(double, double));
        void obtener_variables();
        virtual ~Nodo_funcion_binaria();
        double procesar();

        ////privado
        double (*valor)(double, double);

    protected:
    private:
};

#endif // NODO_FUNCION_BINARIA_H
