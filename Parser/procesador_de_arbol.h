#ifndef PROCESADOR_DE_ARBOL_H
#define PROCESADOR_DE_ARBOL_H
#include <arbol_binario.h>

class procesador_de_arbol
{
    public:
        procesador_de_arbol();
        procesador_de_arbol(arbol_binario* a){this->tree=a;};
        void set_limite_izq(double);
        void set_limite_der(double);
        void set_dx(double);
        std::vector<std::tuple<double,double>> get_coordenadas();
        virtual ~procesador_de_arbol();
    protected:
    private:
        arbol_binario * tree;
        double dx;
        double limite_izq;
        double limite_der;
};

#endif // PROCESADOR_DE_ARBOL_H

