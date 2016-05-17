//Binary Tree Node
//by Saoud Khalifah (s0832050)
//------------------------------
//Binary tree node class.
public class BTNode<E> {
	private E data;
	private BTNode<E> parent;
	private BTNode<E> left;
	private BTNode<E> right;
	
	public BTNode(){
		data = null;
		parent = null;
		left = null;
		right = null;
	}
	public BTNode(E d, BTNode<E> p, BTNode<E> l, BTNode<E> r){
		data = d;
		parent = p;
		left = l;
		right = r;
	}
	public E getData(){
		return data;
	}
	public BTNode<E> getParent(){
		return parent;
	}
	public BTNode<E> getLeft(){
		return left;
	}
	public BTNode<E> getRight(){
		return right;
	}
	public void setData(E d){
		data = d;
	}
	public void setParent(BTNode<E> p){
		parent = p;
	}
	public void setLeft(BTNode<E> l){
		left = l;
	}
	public void setRight(BTNode<E> r){
		right = r;
	}
}
