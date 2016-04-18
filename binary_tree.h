#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <Node.h>
#include <iostream>
template < typename T >
class binary_tree
{
    public:
        binary_tree();
        binary_tree(T a){raiz= new Node<T>(a);};
        virtual ~binary_tree();
        void show();
        ////////////////////  Estos datos iran en la parte privada, por ahora para probar algunas cosas las dejare aqui
        Node<T>* raiz;
    protected:
    private:



};

template < typename T >
binary_tree<T>::binary_tree()
{
    //ctor
}

template < typename T >
binary_tree<T>::~binary_tree()
{
    //dtor
}

template < typename T >
void binary_tree<T>::show(){
    raiz->show();
}



#endif // BINARY_TREE_H
