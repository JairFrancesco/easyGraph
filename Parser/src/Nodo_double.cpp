#include "../include/Nodo_double.h"

Nodo_double::Nodo_double()
{
    //ctor
}

Nodo_double::~Nodo_double()
{
    //dtor
}

Nodo_double::Nodo_double(std::string a){
    this->valor=new double();
    es_variable=true;
    nom_var=a;

}

void Nodo_double::obtener_variables(){

    if(es_variable==true){

        for (int j=0; j<variables->size()  ;j++){

            if(this->nom_var==std::get<0> (variables->at(j) )){
                this->valor=std::get<1> (variables->at(j) );
                return;
            }


        }
        if (variables->size()<=2){
            std::tuple<std::string, double*> temp{this->nom_var,this->valor};
            variables->push_back(temp);
        }
    }

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
