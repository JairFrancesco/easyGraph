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

void Nodo::verif_variables(){
   for (int i=0; i<variables->size()  ;i++){
      for (int j=0; j<variables->size()  ;j++){
         if (std::get<0> (variables->at(i) )==std::get<0>(variables->at(j)) ){
            std::get<1> (variables->at(i) )=std::get<1>(variables->at(j));
            std::cout << "------------------------------------" << std::endl;
         }
      }
   }
}
