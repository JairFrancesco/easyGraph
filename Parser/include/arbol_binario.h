#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "Nodo.h"
#include "Nodo_double.h"
#include "Nodo_funcion_binaria.h"
#include "Nodo_funcion_unaria.h"
#include <algorithm>

class arbol_binario
{
    public:
        arbol_binario();
        arbol_binario(arbol_binario* otro);
        arbol_binario(Nodo*a){raiz=a;a->variables=this->variables;};
        void obtener_variables();
        void verif_variables();
        void cambiar_valor_de(std::string, double);
        arbol_binario* clonar_arbol();
        virtual ~arbol_binario();



    //// privado


        std::vector<std::tuple<std::string,double*>> * variables=new std::vector<std::tuple<std::string, double*>>;
        Nodo*raiz;

    protected:
    private:



};

#endif // ARBOL_BINARIO_H
