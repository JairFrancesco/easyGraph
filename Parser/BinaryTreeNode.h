//Binary Tree Node
//by Jair Francesco Huaman Canqui
//------------------------------
//Binary tree node class.
#include <iostream>
#include <string>

using namespace std;

template <class T>
public class BTNode<T> {
	private:
		T data;
		BTNode<T> parent;
		BTNode<T> left;
		BTNode<T> right;
	
	public:
		BTNode(){
			data = null;
			parent = null;
			left = null;
			right = null;
		}
		BTNode(T d, BTNode<T> p, BTNode<T> l, BTNode<T> r){
			data = d;
			parent = p;
			left = l;
			right = r;
		}
		T getData(){
			return data;
		}
		BTNode<T> getParent(){
			return parent;
		}
		BTNode<T> getLeft(){
			return left;
		}
		BTNode<T> getRight(){
			return right;
		}
		void setData(T d){
			data = d;
		}
		void setParent(BTNode<T> p){
			parent = p;
		}
		void setLeft(BTNode<T> l){
			left = l;
		}
		void setRight(BTNode<T> r){
			right = r;
		}
}
