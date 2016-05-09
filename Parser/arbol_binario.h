#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "Nodo.h"
#include "Nodo_double.h"
#include "Nodo_funcion_binaria.h"
#include "Nodo_funcion_unaria.h"

class arbol_binario
{
    public:
        arbol_binario();
        arbol_binario(Nodo*a){raiz=a;};
        virtual ~arbol_binario();

    //// privado

        Nodo*raiz;
    protected:
    private:

};

#endif // ARBOL_BINARIO_H
