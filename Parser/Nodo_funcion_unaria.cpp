#include "Nodo_funcion_unaria.h"

Nodo_funcion_unaria::Nodo_funcion_unaria()
{
    //ctor
}

Nodo_funcion_unaria::~Nodo_funcion_unaria()
{
    //dtor
}

void Nodo_funcion_unaria::set_valor(double(*& funcion)(double)){
    this->valor=funcion;
}

void Nodo_funcion_unaria::get_valor(double(*& funcion)(double)){
    funcion=*this->valor;

}

double Nodo_funcion_unaria::procesar(){
    return ( (*valor)(this->der->procesar()) );
}
