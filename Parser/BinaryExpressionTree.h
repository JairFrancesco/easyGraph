#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

//BinaryExpressionTree class
//by Jair Francesco Huaman Canqui
//------------------------------
//This class includes the whole binary tree structure management.
//It also has the printTree() routine that is printed sideways in
//the console.

#include <iostream>
#include "BinaryTreeNode.h"
#include <string>

using namespace std;

template<class T>
class BinaryExpressionTree
{
    public:
        BinaryExpressionTree();
        string isOperator(string c);
		void addNode(T* elem);
		void insertOnTree(BTNode<T>* r, BTNode<T>* n);
		string toString();
		string traverse(BTNode<T>* t, int i);
		int getHeight();
		int countLevels(BTNode<T>* t);
		void printSpace(int x);
		int depth(BTNode<T>* r);
		void destruct();
		void BFS();
		void printTree(BTNode<T>* st, int i, int lorr);

    private:
        BTNode<T>* root;
		BTNode<T>* lastNode;
		int sizeTree;
};

template<class T>
BinaryExpressionTree<T>::BinaryExpressionTree(){
    root=NULL;
    lastNode=NULL;
    sizeTree=0;
}

template<class T>
string BinaryExpressionTree<T>::isOperator(string c){
    if(c.compare("+")==0)
        return "+";
    else if(c.compare("-")==0)
        return "-";
    else if(c.compare("*")==0)
        return "*";
    else if(c.compare("/")==0)
        return "/";
    return "";
}

template<class T>
void BinaryExpressionTree<T>::addNode(T* elem){
    if(root == NULL)
    {
        root = new BTNode<T>(elem, NULL, NULL, NULL);
        lastNode = root;
    }else{
        if(isOperator((string)(*(lastNode->getData()))).length() > 0){
            lastNode->setLeft(new BTNode<T>(elem, NULL, NULL, NULL));
            lastNode = lastNode->getLeft();
        }else{
            insertOnTree(root, new BTNode<T>(elem, NULL, NULL, NULL));
        }
    }
    sizeTree++;
}

template<class T>
void BinaryExpressionTree<T>::insertOnTree(BTNode<T>* r, BTNode<T>* n){
    if(r==NULL)
        return;
    if(r->getRight() == NULL){
        r->setRight(n);
        lastNode = r->getRight();
    }else{
        insertOnTree(r->getRight(), n);
    }
}

template<class T>
string BinaryExpressionTree<T>::toString(){
    return traverse(root, 0);
}

template<class T>
string BinaryExpressionTree<T>::traverse(BTNode<T>* t, int i){
    string ret = "";

    cout<<"Enter to TRAVERSE";
    if(t!=NULL){
        traverse(t->getLeft(), i++);
        cout<<""+t->getData()<<endl;
        traverse(t->getRight(), i++);
    }
    return ret;
}

template<class T>
int BinaryExpressionTree<T>::getHeight(){
    return countLevels(root);
}

template<class T>
int BinaryExpressionTree<T>::countLevels(BTNode<T>* t){
    if(t == NULL){
        return 0;
    }
    return (countLevels(t->getLeft()) > countLevels(t->getRight()) ? (countLevels(t->getLeft()) + 1 ): (countLevels(t->getRight()) + 1));
}

template<class T>
void BinaryExpressionTree<T>::printSpace(int x){
    for(int i = 0; i < x; i++)
        cout<<" ";
}

template<class T>
int BinaryExpressionTree<T>::depth(BTNode<T>* r){
    if(r == root)
        return 0;
    else
        return 1 + depth(r);
}

template<class T>
void BinaryExpressionTree<T>::destruct(){
    root = NULL;
    lastNode = NULL;
    sizeTree = 0;
}

template<class T>
void BinaryExpressionTree<T>::BFS(){
    printTree(root, 0, 1);
}

template<class T>
void BinaryExpressionTree<T>::printTree(BTNode<T>* st, int i, int lorr){
    if (st->getRight() != NULL)
    printTree(st->getRight(), i+1, 1);

    string strNew = *(st->getData());
    //cout<<"Value of StrNew:"<<strNew<<endl;
    if(lorr==1 && strNew.length() >0 && (i != getHeight()-1)){
        printSpace(6 * (i+1));
        cout<<"/";
    }else if(lorr == 0 && (strNew).length() > 0)
    {
        printSpace(6 * i);
        cout<<"\\";
    }
    cout<<endl;

    for (int x=0; x<i; x++)
    {
        cout<<"\t";
    }
    cout<<endl<<strNew<<endl;

    if (st->getLeft() != NULL){
        printTree(st->getLeft(), i+1, 0);
    }

}

#endif // BINARYEXPRESSIONTREE_H
