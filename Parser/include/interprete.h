/**
  * @file interprete.h
  * @version 1.0
  * @date 14/07/2016
  * @author Alexis Mendoza
  * @author Jair Huaman
  * @author Luis Bernal
  * @title Clase Interprete
  * @brief Clase para obtener coordenadas de una ecuación.
  * @code
    int main (){
        string ecuacion = "((x+2*y)/sin(y)-12)";
        interprete * interp = new interprete();
        interp -> set_ecuacion(ecuacion);
        interp -> crear_arbol();
        interp->set_diferencial(1);
        interp->set_limite_izq_var1(-100);
        interp->set_limite_der_var1(100);
        interp->set_limite_izq_var2(-100);
        interp->set_limite_der_var2(100);
        std::vector<std::vector<double>>coordenadas=   interp->get_coordenadas();
    }
  * @endcode
  */

#ifndef INTERPRETE_H
#define INTERPRETE_H
#include "Interpretador.h"
#include "procesador_de_arbol.h"

/**
  * Clase para Obtener las coordenadas graficas de una ecuación
  * 
  * @author Alexis Mendoza
  * @author Jair Huaman
  * @author Luis Bernal
  */
class interprete
{
    public:
        interprete();
        /**
          * El Constructor que inicializa con una ecuacion
          *
          */
        interprete(string);

        /**
          * @brief set_ecuacion Establece la ecuación que usara el interpretador.
          * @param ecuacion Cadena para establecer el valor de la ecuacion
          * @return
          */
        void set_ecuacion(string ecuacion);
        /**
          * @brief crear_arbol Crea el arbol de expresiones
          * @return
          */
        void crear_arbol();
        /**
          * @brief set_diferencial Establece el diferencial
          * @param dx Indica el diferencial que usara el interpretador
          * @return
          */
        void set_diferencial(double dx);
        /**
          * @brief set_limite_izq_var1 establece el limite de x por la izquierda
          * @param limIzVar1 Indica el limite por la izquierda
          * @return
          */
        void set_limite_izq_var1(double limIzVar1);
        /**
          * @brief establece el limite de x por la derecha
          * @param limDerVar1 Indica el limite por la derecha
          * @return
          */
        void set_limite_der_var1(double limDerVar1);
        /**
          * @brief establece el limite de y por la izquierda
          * @param limIzVar2 Indica el limite por la derecha
          * @return
          */
        void set_limite_izq_var2(double limIzVar2);
        /**
          * @brief establece el limite de y por la derecha
          * @param limDerVar2 Indica el limite por la derecha
          * @return
          */
        void set_limite_der_var2(double limDerVar2);
        /**
          * @brief Obtiene todas las coordenadas
          * @return Un Vector bidimensional de tipo Double con todas las coordenadas
          */
        std::vector<std::vector<double>> get_coordenadas();
        string delUnnecessary(string &str);
        string ecuacion;
        int* cont_x;
        int* cont_y;
        

        virtual ~interprete();
    protected:
    private:
        Interpretador * interpretador;
        procesador_de_arbol * procesador;
        

};

#endif // INTERPRETE_H
