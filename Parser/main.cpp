#include "include/Nodo.h"
#include "include/Nodo_double.h"
#include "include/Nodo_funcion_binaria.h"
#include "include/Nodo_funcion_unaria.h"
#include "include/arbol_binario.h"
#include "include/procesador_de_arbol.h"
#include "include/Interpretador.h"

using namespace std;



int main()
{
    /////////// por ahora funciona con +, - , *, /, ^, sin, tan
    //////////// aun hay un caso que no resuelvo con parentesis
    std::vector<string> v;
    string ecuacion="(2^x)*(sin(30))";

    Interpretador * interp = new Interpretador();
    interp->transformar(ecuacion, v);
    interp->tree->obtener_variables();

    procesador_de_arbol * procesador= new procesador_de_arbol(interp->tree);
    procesador->set_dx(1);
    procesador->set_limite_izq(0);
    procesador->set_limite_der(10);
    auto coor =procesador->get_coordenadas();

    for (int i=0; i<coor.size();i++){
        std::cout << "x" << " " << "y" << std::endl;
        std::cout<<  (std::get<0> (coor.at(i)) ) << " " << (std::get<1> (coor.at(i)) )<<endl ;
    }


    return 0;

}
