#ifndef NODE_H
#define NODE_H
#include <iostream>
template <typename T>
class Node
{
    public:
        Node(T a){value=new T(a);std::cout<<get_value()<<std::endl;};
        Node();
        void set_value(T a){value=&a;};
        void add_left_p(T a){left_p=new Node<T>(a);};
        void add_right_p(T a){right_p=new Node<T>(a);};
        T get_value(){return *value;};
        void show();
        virtual ~Node();
        ////////////////////  Estos datos iran en la parte privada, por ahora para probar algunas cosas las dejare aqui
        Node<T>* left_p=nullptr;
        Node<T>* right_p=nullptr;
        T* value;
    protected:
    private:


};

template <typename T>
void Node<T>::show(){
    if(left_p==nullptr && right_p==nullptr){
        std::cout<<*value<<" ";
    }

    else{
        if(left_p!=nullptr){
            left_p->show();
        }
        std::cout<<*value<<" ";
        if(right_p!=nullptr){
            right_p->show();
        }
    }


}

template <typename T>
Node<T>::Node()
{
    //ctor
}

template <typename T>
Node<T>::~Node()
{
    //dtor
}


#endif // NODE_H
