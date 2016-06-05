#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include "arbol_binario.h"


using namespace std;

class Interpretador
{
    public:
        Interpretador();
        virtual ~Interpretador();
        void elim_vacio(std::vector<string>&);
        void separar_en_dos(std::vector<string>&, string);
        void reverse_string(string& );
        bool verif_oper(string& );
        void verif_ope(string& ope);
        bool buscar_ope(string, string, std::vector<string>&);
        void transformar(string text,vector<string>&);
        void transformar(string text, Nodo*, bool);
        bool is_number(const std::string&);
        bool isAlpha(const string&);
        double string_to_double(string);
        void elim_parent(string&);

        map<string,double(*)(double)>funciones_unarias;
        map<string,double(*)(double,double)>funciones_binarias;
        map<string,int>prioridad_funciones;
        arbol_binario * tree;
    protected:
    private:
};

#endif // INTERPRETADOR_H
