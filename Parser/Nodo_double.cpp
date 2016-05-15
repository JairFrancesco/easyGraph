#include "Nodo_double.h"

Nodo_double::Nodo_double()
{
    //ctor
}

Nodo_double::~Nodo_double()
{
    //dtor
}

void Nodo_double::get_valor(double* a){
    *a=*valor;
}

void Nodo_double::set_valor(double a){
    *valor=a;
}

double Nodo_double::procesar(){
    return *this->valor;
}
