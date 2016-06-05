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

double cubo(double x){
    return pow(x,3);
}

double v_absoluto(double x){
    return abs(x);
}


double seno(double x){
    return sin(x*PI/180);
}

double coseno(double x){
    return cos(x*PI/180);
}

double cotangente(double x){
    return (1/tan(x*PI/180));
}

double secante(double x){
    return (1/(cos(x*PI/180)));
}

double cosecante(double x){
    return (1/(sin(x*PI/180)));
}

double tangente(double x){
    return tan(x*PI/180);
}

double arco_seno(double x){
    return asin(x*PI/180);
}

double arco_coseno(double x){
    return acos(x*PI/180);
}

double arco_tangente(double x){
    return atan(x*PI/180);
}

double arco_secante(double x){
    return acos(1/(x*PI/180));
}

double arco_cosecante(double x){
    return asin(1/(x*PI/180));
}

double arco_cotangente(double x){
    return atan(1/(x*PI/180));
}

double coseno_hiperbolico(double x){
    return cosh(x*PI/180);
}

double seno_hiperbolico(double x){
    return sinh(x*PI/180);
}

double tangente_hiperbolico(double x){
    return tanh(x*PI/180);
}

double arcocoseno_hiperbolico(double x){
    return acosh(x*PI/180);
}

double arcoseno_hiperbolico(double x){
    return asinh(x*PI/180);
}

double arcotangente_hiperbolico(double x){
    return atanh(x*PI/180);
}

double arco_cosecante_hiperbolico(double x){
    return asinh(1/(x*PI/180));
}

double arco_secante_hiperbolico(double x){
    return acosh(1/(x*PI/180));
}

double arco_cotangente_hiperbolico(double x){
    return atanh(1/(x*PI/180));
}
