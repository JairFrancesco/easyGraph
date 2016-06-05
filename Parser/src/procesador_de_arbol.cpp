#include "../include/procesador_de_arbol.h"

procesador_de_arbol::procesador_de_arbol()
{
    //ctor
}

procesador_de_arbol::~procesador_de_arbol()
{
    //dtor
}

void procesador_de_arbol::set_limite_izq(double a){
    this->limite_izq=a;
}

void procesador_de_arbol::set_limite_der(double a){
    this->limite_der=a;
}

void procesador_de_arbol::set_dx(double a){
    this->dx=a;
}

std::vector<std::tuple<double,double>> procesador_de_arbol::get_coordenadas(){
    std::vector<std::tuple<double,double>> temp2;
    for(double i=(this->limite_izq);i<=this->limite_der;){
        if(tree->variables->size()!=0){
            *(std::get<1>(tree->variables->at(0)))=i;
        }
        std::tuple<double,double> temp1{i,tree->raiz->procesar()};
        temp2.push_back(temp1);
        i+=dx;
    }
    return temp2;
}
