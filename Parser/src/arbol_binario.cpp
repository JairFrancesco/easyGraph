#include "../include/arbol_binario.h"

arbol_binario::arbol_binario()
{
    //ctor
}

arbol_binario::~arbol_binario()
{
    //dtor
}

void arbol_binario::cambiar_valor_de(std::string var, double num){


    for (int i=0; i<variables->size()  ;i++){
        if(std::get<0> (variables->at(i) )==var ){
            *(std::get<1> (variables->at(i) ) )= num;
            break;
        }
    }
}

void arbol_binario::obtener_variables(){
   this->raiz->obtener_variables();
}
