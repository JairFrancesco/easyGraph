#ifndef INTERPRETE_H
#define INTERPRETE_H
#include "Interpretador.h"
#include "procesador_de_arbol.h"

class interprete
{
    public:
        interprete();
        interprete(string);
        void set_ecuacion(string);
        void crear_arbol();
        void set_diferencial(double);
        void set_limite_izq_var1(double);
        void set_limite_der_var1(double);
        void set_limite_izq_var2(double);
        void set_limite_der_var2(double);
        std::vector<std::vector<double>> get_coordenadas();
        string ecuacion;
        virtual ~interprete();
    protected:
    private:
        Interpretador * interpretador;
        procesador_de_arbol * procesador;

};

#endif // INTERPRETE_H
