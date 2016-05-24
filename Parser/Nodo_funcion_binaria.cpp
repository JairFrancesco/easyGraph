#include "Nodo_funcion_binaria.h"

Nodo_funcion_binaria::Nodo_funcion_binaria()
{
    //ctor
}

Nodo_funcion_binaria::~Nodo_funcion_binaria()
{
    //dtor
}

void Nodo_funcion_binaria::obtener_variables(){
    this->izq->obtener_variables();
    this->der->obtener_variables();
}


void Nodo_funcion_binaria::set_valor(double(*& funcion)(double, double)){
    this->valor=funcion;
}

void Nodo_funcion_binaria::get_valor(double(*& funcion)(double, double)){
    funcion=*this->valor;

}

double Nodo_funcion_binaria::procesar(){
    return ( (*valor) ( this->izq->procesar() , this->der->procesar() ) );
}
