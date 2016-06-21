#ifndef NODO_H
#define NODO_H
#include <tuple>
#include <iostream>
#include <vector>


class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        virtual void set_valor(){};
        void agregar_der(Nodo*);
        void agregar_izq(Nodo*);
        virtual void get_valor(double* a){};
        virtual void set_valor(double){};
        virtual void obtener_variables(){};
        ////privado
        virtual void get_valor(double(*&funcion)(double, double)){};
        virtual void set_valor(double(*& funcion)(double, double)){};
        virtual void get_valor(double(*&funcion)(double)){};
        virtual void set_valor(double(*& funcion)(double)){};

        virtual double procesar(){};
        void verif_variables();
        ////privado
        Nodo * izq;
        Nodo * der;
        std::vector<std::tuple<std::string,double*>> *variables;

    protected:
    private:

};


#endif // NODO_H
