#include <ostream>
#include <math.h>

////////////////// funciones binarias

#define PI 3.14159265



double suma(double x, double y){
    return x+y;
}

double resta(double x, double y){
    return x-y;
}

double division(double x, double y){
    return x/y;
}

double multiplicacion(double x, double y){
    return x*y;
}

double modulo(double x, double y){
    return (double) ( ((int)x)%((int)y) );
}

double potencia(double x, double y){
    return pow(x,y);
}




////////////////// funciones unarias

double cuadrado(double x){
    return x*x;
}

double raiz(double x){
    return sqrt(x);
}

double cubo(double x){
    return pow(x,3);
}

double v_absoluto(double x){
    return abs(x);
}

double log(double x)
{
    //std::cout<<"calculating log"<<std::endl;
    return log2(x);
}

double seno(double x){
    return sin(x);
}

double coseno(double x){
    return cos(x);
}

double cotangente(double x){
    return (1/tan(x));
}

double secante(double x){
    return (1/(cos(x)));
}

double cosecante(double x){
    return (1/(sin(x)));
}

double tangente(double x){
    return tan(x);
}

double arco_seno(double x){
    return asin(x);
}

double arco_coseno(double x){
    return acos(x);
}

double arco_tangente(double x){
    return atan(x);
}

double arco_secante(double x){
    return acos(1/(x));
}

double arco_cosecante(double x){
    return asin(1/(x));
}

double arco_cotangente(double x){
    return atan(1/(x));
}


double coseno_hiperbolico(double x){
    return cosh(x);
}

double seno_hiperbolico(double x){
    return sinh(x);
}

double tangente_hiperbolico(double x){
    return tanh(x);
}

double cosecante_hiperbolico(double x){
    return sinh(1/(x));
}

double secante_hiperbolico(double x){
    return cosh(1/(x));
}

double cotangente_hiperbolico(double x){
    return tanh(1/(x));
}

double arco_coseno_hiperbolico(double x){
    return acosh(x);
}

double arco_seno_hiperbolico(double x){
    return asinh(x);
}

double arco_tangente_hiperbolico(double x){
    return atanh(x);
}

double arco_cosecante_hiperbolico(double x){
    return asinh(1/(x));
}

double arco_secante_hiperbolico(double x){
    return acosh(1/(x));
}

double arco_cotangente_hiperbolico(double x){
    return atanh(1/(x));
}


