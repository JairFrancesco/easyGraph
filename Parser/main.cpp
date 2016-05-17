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

boolean precedence(string c1, string c2){
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


string isParenthesis(String c){
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



