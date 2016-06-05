#include "../include/Nodo.h"

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
    a->variables= this->variables;
}

void Nodo::agregar_izq(Nodo* a){
    this->izq=a;
    a->variables= this->variables;
}
