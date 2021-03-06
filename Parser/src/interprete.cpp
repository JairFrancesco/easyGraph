#include "../include/interprete.h"

interprete::interprete()
{


}

interprete::interprete(string text){

}

interprete::~interprete()
{

}

string interprete::delUnnecessary(string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void interprete::set_ecuacion(string text){
  delete this->interpretador;
  this->interpretador=new Interpretador();
  string newEquation = this->delUnnecessary(text);
  this->ecuacion=newEquation;

}

void interprete::set_diferencial(double dx){
  this->procesador->set_dx(dx);
}

void interprete::set_limite_izq_var1(double lim){
  this->procesador->set_limite_izq_var1(lim);
}
void interprete::set_limite_der_var1(double lim){
  this->procesador->set_limite_der_var1(lim);
}
void interprete::set_limite_izq_var2(double lim){
  this->procesador->set_limite_izq_var2(lim);
}
void interprete::set_limite_der_var2(double lim){
  this->procesador->set_limite_der_var2(lim);
}

void interprete::crear_arbol(){
  interpretador->verif_sintaxis(this->ecuacion);
  interpretador->transformar(this->ecuacion);
  interpretador->tree->raiz->obtener_variables();
  interpretador->tree->verif_variables();
  this->procesador= new procesador_de_arbol(this->interpretador->tree);
  this->cont_x=&procesador->cont_x;
  this->cont_y=&procesador->cont_y;
}

std::vector<std::vector<double>> interprete::get_coordenadas(){

  return this->procesador->get_coordenadas();
}
