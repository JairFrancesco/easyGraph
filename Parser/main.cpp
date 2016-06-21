#include "include/interprete.h"

using namespace std;



int main()
{

    //----------------------------tutorial------------------------
    //---------------------ejemplo con 2 variables
    // no es necesario especificar el numero de variables
    // cada variable puede ser cualquier string
    // por ahora no puedes obviar operadores * por ejemplo 2x+3 lo deberias ingresar como 2*x+3
    // aun tengo hay problemas con los negativos, no usarlos!!!  example ->  -sin(-x)
    // para campiar de ecuacion solo usar set_ecuacion(), posteriormente crear_arbol() y get_coordenadas()
    // el diferencial define cada cuandto se hallara un punto
    // set_limite_izq_var1  y  set_limite_izq_var1 se usan para una sola variable , por default es  -10 y 10
    // set_limite_izq_var2  y  set_limite_izq_var2 solo se usan con dos variables, por defautl es -10 y 10

    // ejemplo con tres variables

    string ecuacion = "((x+2*y)/sin(y)-12)";
    interprete * interp = new interprete();
    interp -> set_ecuacion(ecuacion);
    interp -> crear_arbol();
    interp->set_diferencial(1); // por defecto el diferencial es 1
    //por defecto los limites van de -10 a 10, por lo que podrias omitir las proximas 4 lineas
    interp->set_limite_izq_var1(-100);
    interp->set_limite_der_var1(100);
    interp->set_limite_izq_var2(-100);
    interp->set_limite_der_var2(100);
    std::vector<std::vector<double>>coordenadas=   interp->get_coordenadas();  // el metodo get_coordenadas es obvio

    /// esto es solo para visualizar las coordenadas
    for (auto it : coordenadas){

        for (auto ite : it){
          std::cout << ite <<" " ;
        }
        std::cout << "" << std::endl;

    }



    //-----------------------------ejemplo con una variables

  /*

    string ecuacion = "2*x+34";
    interprete * interp = new interprete();
    interp -> set_ecuacion(ecuacion);
    interp -> crear_arbol();
    std::vector<std::vector<double>>coordenadas=   interp->get_coordenadas();


    for (auto it : coordenadas){

        for (auto ite : it){
          std::cout << ite <<" " ;
        }
        std::cout << "" << std::endl;

    }
  */

// --------------------------------esto es un bucle para ingresar probar ecuaciones
/*


    string ecuacion;
    interprete * interp=new interprete();  //Lo primero es crear un objeto de interprete
    while(true){
      std::cout << "Ingrese ecuacion" << std::endl;
      std::cin>>ecuacion;
      interp->set_ecuacion(ecuacion); //Aqui ingresas tu ecuacion como string
      interp->crear_arbol();// luego de ingresar la ecuacion se crea el arbol con esta funcion
      std::vector<std::vector<double> > coor =  interp->get_coordenadas(); // y es con esta que se obtiene los puntos

      for (auto it : coor){

          for (auto ite : it){
            std::cout << ite <<" " ;
          }
          std::cout << "" << std::endl;

      }
    }

*/
    return 0;

}
