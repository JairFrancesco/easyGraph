#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

//Binary Tree Node
//by Jair Francesco Huaman Canqui
//------------------------------
//Binary tree node class.
#include <iostream>
#include <string>

using namespace std;

template <class T>
class BTNode {
	private:
		T* data;
		BTNode<T>* parent;
		BTNode<T>* left;
		BTNode<T>* right;

	public:
		BTNode();
		BTNode(T* d, BTNode<T>* p, BTNode<T>* l, BTNode<T>* r);
		T* getData();
		BTNode<T>* getParent();
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
		void setData(T* d);
		void setParent(BTNode<T>* p);
		void setLeft(BTNode<T>* l);
		void setRight(BTNode<T>* r);
};

template <class T>
BTNode<T>::BTNode(){
    data=NULL;
    parent=NULL;
    left=NULL;
    right=NULL;
}

template <class T>
BTNode<T>::BTNode(T* d, BTNode<T>* p, BTNode<T>* l, BTNode<T>* r){
    data = d;
    parent = p;
    left = l;
    right = r;
};

template <class T>
T* BTNode<T>::getData(){
    return data;
}

template <class T>
BTNode<T>* BTNode<T>::getParent(){
    return parent;
}

template <class T>
BTNode<T>* BTNode<T>::getLeft(){
    return left;
};

template <class T>
BTNode<T>* BTNode<T>::getRight(){
    return right;
};

template <class T>
void BTNode<T>::setData(T* d){
	data = d;
};

template <class T>
void BTNode<T>::setParent(BTNode<T>* p){
	parent = p;
};
template <class T>
void BTNode<T>::setLeft(BTNode<T>* l){
	left = l;
};
template <class T>
void BTNode<T>::setRight(BTNode<T>* r){
	right = r;
};


#endif // BINARYTREENODE_H
