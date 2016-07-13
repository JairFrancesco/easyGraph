#ifndef PROCESADOR_DE_ARBOL_H
#define PROCESADOR_DE_ARBOL_H
#include "arbol_binario.h"
#include "tipos de datos.h"



class procesador_de_arbol
{
    public:
        procesador_de_arbol();
        procesador_de_arbol(arbol_binario* a){this->tree=a;};
        void set_limite_var(double, double ,std::string);
        void set_limite_izq_var1(double);
        void set_limite_der_var1(double);
        void set_limite_izq_var2(double);
        void set_limite_der_var2(double);
        void set_dx(double);
        std::vector<std::vector<double>> get_coordenadas();

        virtual ~procesador_de_arbol();
    protected:
    private:
        arbol_binario * tree;
        double dx=0.1;
        double limite_izq_var1=-10;
        double limite_der_var1=10;
        double limite_izq_var2=-10;
        double limite_der_var2=10;

};

#endif // PROCESADOR_DE_ARBOL_H
