#include <iostream>
//#include <string>
#include <sstream>
#include <stdio.h>
#include "include/Nodo.h"
#include "include/Nodo_double.h"
#include "include/Nodo_funcion_binaria.h"
#include "include/Nodo_funcion_unaria.h"
#include "include/arbol_binario.h"
#include "include/funciones.h"
#include "include/procesador_de_arbol.h"


using namespace std;


string isOperator(string c){
        if(c.compare("+")==0)
            return "+";
        else if(c.compare("-")==0)
            return "-";
        else if(c.compare("*")==0)
            return "*";
        else if(c.compare("/")==0)
            return "/";
        return "";
}

bool precedence(string c1, string c2){
        int i1 = 0;
        int i2 = 0;
        if(c1.compare("+") == 0)
            i1 = 1;
        else if(c1.compare("-") == 0)
            i1 = 2;
        else if(c1.compare("*") == 0)
            i1 = 3;
        else if(c1.compare("/") == 0)
            i1 = 4;
        if(c2.compare("+") == 0)
            i2 = 1;
        else if(c2.compare("-") == 0)
            i2 = 2;
        else if(c2.compare("*") == 0)
            i2 = 3;
        else if(c2.compare("/") == 0)
            i2 = 4;
        if(i1 >= i2)
            return true;
        else
            return false;
}


string isParenthesis(string c){
        if(c.compare("(")==0)
            return "(";
        else if(c.compare(")")==0)
            return ")";
        return "";
}
int p(char op)
{
    int p;
    switch (op)
    {
        case '+' :
        case '-' :
             p = 1;
             break;
        case '*' :
        case '/' :
             p = 2;
             break;
        default:
             p = 0;
             break;
    }
    return p;
}




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
    Nodo * a= new Nodo_double(5);
    Nodo * b= new Nodo_double(2);
    Nodo * c= new Nodo_double(4);
    Nodo * d= new Nodo_double(6);


    Nodo * sum=new Nodo_funcion_binaria(suma);
    Nodo * cuadrad=new Nodo_funcion_unaria(cuadrado);
    Nodo * multi=new Nodo_funcion_binaria(multiplicacion);

    Nodo * variable= new Nodo_double("x");

    arbol_binario * tree= new arbol_binario(sum);
    tree->raiz->agregar_der(cuadrad);
    tree->raiz->der->agregar_der(d);
    tree->raiz->agregar_izq(multi);
    tree->raiz->izq->agregar_izq(a);
    tree->raiz->izq->agregar_der(variable);
    tree->obtener_variables();

    procesador_de_arbol * procesador= new procesador_de_arbol(tree);
    procesador->set_dx(0.7);
    procesador->set_limite_izq(150);
    procesador->set_limite_der(1500);
    auto coor =procesador->get_coordenadas();

    for (int i=0; i<coor.size();i++){
        std::cout<<  (std::get<0> (coor.at(i)) ) << " " << (std::get<1> (coor.at(i)) )<<endl ;
    }


    return 0;

}
