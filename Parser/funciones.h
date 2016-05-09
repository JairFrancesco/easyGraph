#include <ostream>
#include <math.h>

////////////////// funciones binarias

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

double seno(double x){
    return sin(x);
}

double coseno(double x){
    return cos(x);
}

double tangente(double x){
    return tan(x);
}

