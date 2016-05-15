#ifndef NODO_H
#define NODO_H


class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        virtual void set_valor(){};
        void agregar_der(Nodo*);
        void agregar_izq(Nodo*);
        virtual void get_valor(double* a){};
        virtual void set_valor(double){};
        ////privado
        virtual void get_valor(double(*&funcion)(double, double)){};
        virtual void set_valor(double(*& funcion)(double, double)){};
        virtual void get_valor(double(*&funcion)(double)){};
        virtual void set_valor(double(*& funcion)(double)){};

        virtual double procesar(){};
        Nodo * izq;
        Nodo * der;
    protected:
    private:

};

#endif // NODO_H
