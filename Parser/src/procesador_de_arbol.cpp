#include "../include/procesador_de_arbol.h"
#include <thread>

procesador_de_arbol::procesador_de_arbol()
{
    //ctor
}

procesador_de_arbol::~procesador_de_arbol()
{
    //dtor
}

void procesador_de_arbol::set_limite_var(double lim_izq, double lim_der, std::string nom_var){
    if (nom_var== std::get<0>(tree->variables->at(0) )){
        this->limite_izq_var1=lim_izq;
        this->limite_der_var1=lim_der;
    }
    else{
        this->limite_izq_var2=lim_izq;
        this->limite_der_var2=lim_der;
    }
}


void procesador_de_arbol::set_limite_izq_var1(double a){
    this->limite_izq_var1=a;
}

void procesador_de_arbol::set_limite_der_var1(double a){
    this->limite_der_var1=a;
}

void procesador_de_arbol::set_limite_izq_var2(double a){
    this->limite_izq_var2=a;
}

void procesador_de_arbol::set_limite_der_var2(double a){
    this->limite_der_var2=a;
}

void procesador_de_arbol::set_dx(double a){
    this->dx=a;
}

std::vector<std::vector<double>> procesador_de_arbol::get_coordenadas(){
    std::vector<std::vector<double>> v_temp2;
    if(tree->variables->size()==1){
        double halfLimit = this->limite_der_var1/2;
        //Thread1
        std::thread t1([&v_temp2, this, halfLimit](){
            for(double i=(this->limite_izq_var1);i<=halfLimit;i+=dx){

                *(std::get<1>(tree->variables->at(0)))=i;
                std::vector<double> v_temp1;
                v_temp1.push_back(i);
                v_temp1.push_back(tree->raiz->procesar());
                v_temp2.push_back(v_temp1);
            }
        });
        //Thread2
        std::thread t2([&v_temp2, this, halfLimit](){
            for(double i=halfLimit+dx;i<=this->limite_der_var1;i+=dx){

                *(std::get<1>(tree->variables->at(0)))=i;
                std::vector<double> v_temp1;
                v_temp1.push_back(i);
                v_temp1.push_back(tree->raiz->procesar());
                v_temp2.push_back(v_temp1);
            }
        });
        t1.join();
        t2.join();
    }

    else if(tree->variables->size()==2){
        double thirdLimit = this->limite_der_var1/3;
        //Thread1
        std::thread t1([&v_temp2, this, thirdLimit](){
            for(double i=(this->limite_izq_var1);i<=thirdLimit;i+=dx){

                *(std::get<1>(tree->variables->at(0)))=i;
                for (double j=(this->limite_izq_var2);j<=this->limite_der_var2;j+=dx){
                    *(std::get<1>(tree->variables->at(1)))=j;
                    std::vector<double> v_temp1;
                    v_temp1.push_back(i);
                    v_temp1.push_back(j);
                    v_temp1.push_back(tree->raiz->procesar());
                    v_temp2.push_back(v_temp1);
                }
            }
        });

        //Thread2
        std::thread t2([&v_temp2, this, thirdLimit](){
            for(double i=(thirdLimit+dx);i<=(thirdLimit*2);i+=dx){

                *(std::get<1>(tree->variables->at(0)))=i;
                for (double j=(this->limite_izq_var2);j<=this->limite_der_var2;j+=dx){
                    *(std::get<1>(tree->variables->at(1)))=j;
                    std::vector<double> v_temp1;
                    v_temp1.push_back(i);
                    v_temp1.push_back(j);
                    v_temp1.push_back(tree->raiz->procesar());
                    v_temp2.push_back(v_temp1);
                }
            }
        });

        //Thread3
        std::thread t3([&v_temp2, this, thirdLimit](){
            for(double i=(thirdLimit*2+dx);i<=this->limite_der_var1;i+=dx){

                *(std::get<1>(tree->variables->at(0)))=i;
                for (double j=(this->limite_izq_var2);j<=this->limite_der_var2;j+=dx){
                    *(std::get<1>(tree->variables->at(1)))=j;
                    std::vector<double> v_temp1;
                    v_temp1.push_back(i);
                    v_temp1.push_back(j);
                    v_temp1.push_back(tree->raiz->procesar());
                    v_temp2.push_back(v_temp1);
                }
            }
        });

        t1.join();
        t2.join();
        t3.join();
    }
    else if(tree->variables->size()==0){
        for (double i= (this->limite_izq_var1);i<=this->limite_der_var1;i+=dx){
            std::vector<double> v_temp1;
            v_temp1.push_back(i);
            v_temp1.push_back(tree->raiz->procesar());
            v_temp2.push_back(v_temp1);
        }
    }
    return v_temp2;
}
