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
        
    /*  Primero que nada hay tres tipos de Nodo 
    nodos a doubles, a funciones con un solo 
    operando y a funciones con dos operandos
    
    y se declaran como los siguientes nodos
    P.D : la creacion de los nodos las deberia hacer una clase automaticamente
    */ 
    
    Nodo * a= new Nodo_double(5);
    Nodo * b= new Nodo_double(2);
    Nodo * c= new Nodo_double(4);
    Nodo * d= new Nodo_double(6);
    
    //Las variables las declaras de la misma forma que un numero, dando como argumento el nombre de la variable
    Nodo * variable= new Nodo_double("x");

    /*Los nodos de funciones tienen como entrada funciones , 
    de las cuales guardan un puntero, estas se encuentran en
    include/funciones.h */
    Nodo * sum=new Nodo_funcion_binaria(suma);
    Nodo * cuadrad=new Nodo_funcion_unaria(cuadrado);
    Nodo * multi=new Nodo_funcion_binaria(multiplicacion);


    //aqui el arbol tiene como argumento el nodo que servira de raiz(siempre sera un nodo de funcion)
    arbol_binario * tree= new arbol_binario(sum);
    
    /*aqui se va creando el arbol
    basicamente atravez de el arbol
    se accede a los nodos y se agrega
    el puntero a sus ramas izquierda 
    y derecha
    P.D : esto tambien deberia hacerlo una clase automaticamente */
    tree->raiz->agregar_der(cuadrad);
    tree->raiz->der->agregar_der(d);
    tree->raiz->agregar_izq(multi);
    tree->raiz->izq->agregar_izq(a);
    tree->raiz->izq->agregar_der(variable);
    tree->obtener_variables();

    /*Esta es la cosa que que te devuelve las coordenadas 
    x,y de los puntos a graficar, tiene como argumento el puntero
    a nuestro arbol, ademas posee metodos para definir los limites entre los 
    que queremos hallar los puntos , y cada cuanto hallar un punto en los
    limites dados(set_dx) */ 
    procesador_de_arbol * procesador= new procesador_de_arbol(tree);
    procesador->set_dx(0.7);
    procesador->set_limite_izq(150);
    procesador->set_limite_der(1500);
    
    //esto te devuelve un vector de tuplas con las coordenadas
    auto coor =procesador->get_coordenadas();

    //esto es solo para mostrar los puntos que se hallan
    for (int i=0; i<coor.size();i++){
        std::cout<<  (std::get<0> (coor.at(i)) ) << " " << (std::get<1> (coor.at(i)) )<<endl ;
    }
    
    // Estas clases aun no son a prueba de fallos >_< 

    return 0;

}
