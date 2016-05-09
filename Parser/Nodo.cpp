#include "Nodo.h"

Nodo::Nodo()
{
    //ctor
}

Nodo::~Nodo()
{
    //dtor
}



void Nodo::agregar_der(Nodo* a){
    this->der=a;
}

void Nodo::agregar_izq(Nodo* a){
    this->izq=a;
}
