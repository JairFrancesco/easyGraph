#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <map>
#include <iostream>
#include <vector>
#include <string>
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
        
        bool buscar_ope(string, string, std::vector<string>&);
        void transformar(string text);
        void transformar(string text, Nodo*, bool);
        
        double string_to_double(string);
        void elim_parent(string&);
        bool esta_en(string text, string ope);
        std::string verif_sintaxis(std::string);
        void fix_multi(std::vector<string>&);
        std::vector<string> string_to_vector(string);
        void fix_multiplicaciones(std::vector<string>&);
        void fix_negativos(std::vector<string>&);
        void fix_operaciones_unarias(std::vector<string>&);
        string get_operador_mayor_prioridad(std::vector<string>);
        //--------------metodos de apoyo--------------------------
        int get_operador_prioridad(string);
        bool es_operador(string);
        bool is_number(const std::string&);
        bool isAlpha(const string&);
        bool es_operador_unario(string);
        bool es_operador_binario(string);
        bool es_expresion(string);

        map<string,double(*)(double)>funciones_unarias;
        map<string,double(*)(double,double)>funciones_binarias;
        map<string,int>prioridad_funciones;
        arbol_binario * tree;
    protected:
    private:
};

#endif // INTERPRETADOR_H
