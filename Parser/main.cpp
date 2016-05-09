#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Nodo_double.h"
#include "Nodo_funcion_binaria.h"
#include "Nodo_funcion_unaria.h"
#include "arbol_binario.h"
#include "Nodo.h"
#include "funciones.h"

using namespace std;



double string_to_double(std::string strg){
    if(strg=="x"){
        double x;
        return x;
    }
    else{
        double num;
        std::stringstream stream;
        stream << strg;
        stream >> num;
        return num;
    }

}


int main()
{

    Nodo * a= new Nodo_double(32);
    Nodo * b= new Nodo_double(21);
    Nodo * c= new Nodo_double(4);


    double (*fun1)(double, double);
    double (*fun2)(double);
    fun1=&suma;
    fun2=&cuadrado;
    Nodo * d=new Nodo_funcion_binaria(fun1);
    Nodo * e=new Nodo_funcion_unaria(fun2);



    arbol_binario * tree= new arbol_binario(e);
    tree->raiz->agregar_der(c);
    tree->raiz->agregar_izq(d);
    tree->raiz->izq->agregar_izq(a);
    tree->raiz->izq->agregar_der(b);



    return 0;

}
