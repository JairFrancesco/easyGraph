//LinkedBinaryTree class
//by Saoud Khalifah (s0832050)
//------------------------------
//This class includes the whole binary tree structure management.
//It also has the printTree() routine that is printed sideways in
//the console.




public class LinkedBinaryTree<E> {

	
	private BTNode<E> root;
	private BTNode<E> lastNode;
	private int size;
	
	public LinkedBinaryTree(){
		root = null;
		lastNode = null;
		size = 0;
	}
	public static String isOperator(String c){
		if(c.equals("+"))
			return "+";
		else if(c.equals("-"))
			return "-";
		else if(c.equals("*"))
			return "*";
		else if(c.equals("/"))
			return "/";
		return "";
	}
	public void addNode(E elem){
		if(root == null)
		{
			root = new BTNode<E>(elem, null, null, null);
			lastNode = root;
		}else{
			if(isOperator((String)lastNode.getData()).length() > 0){
				lastNode.setLeft(new BTNode<E>(elem, null, null, null));
				lastNode = lastNode.getLeft();
			}else{
				insert(root, new BTNode<E>(elem, null, null, null));
			}
		}
		size++;
	}
	public void insert(BTNode<E> r, BTNode<E> n){
			if(r==null)
				return;
			if(r.getRight() == null){
				r.setRight(n);
				lastNode = r.getRight();
			}else{
				insert(r.getRight(), n);
			}
		
	}
	public String toString(){
		return traverse(root, 0);
	}
	public String traverse(BTNode<E> t, int i){
		String ret = "";
		
		
		if(t!=null){
			traverse(t.getLeft(), i++);
			System.out.print("" + t.getData() + "\n");
			
			traverse(t.getRight(), i++);
		}
		return ret;
	}
	public int getHeight(){
		return countLevels(root);
	}
	public int countLevels(BTNode<E> t)
	{
		if(t == null){
			return 0;
		}
		
		return (countLevels(t.getLeft()) > countLevels(t.getRight()) ? (countLevels(t.getLeft()) + 1 ): (countLevels(t.getRight()) + 1));
	}
	public void printSpace(int x){
		for(int i = 0; i < x; i++)
			System.out.print(" ");
	}
	public int depth(BTNode<E> r){
		if(r == root)
			return 0;
		else
			return 1 + depth(r);
	}
	public void destruct(){
		root = null;
		lastNode = null;
		size = 0;
	}

	public void BFS()    
	{      
		printTree(root, 0, 1);
		
	}
	private void printTree(BTNode<E> st, int i, int lorr)
	{
	 
	if (st.getRight() != null)
	printTree(st.getRight(), i+1, 1);
	 
	
	if(lorr==1 && st.getData().toString().length() >0 && (i != getHeight()-1)){
		printSpace(6 * (i+1));
		System.out.print("/");
	}else if(lorr == 0 && st.getData().toString().length() > 0)
	{
		printSpace(6 * i);
		System.out.print("\\");
	}
	System.out.println("\n");
	 
	for (int x=0; x<i; x++)
	System.out.print("\t");
	 
	System.out.println(st.getData());
	 
	if (st.getLeft() != null)
	printTree(st.getLeft(), i+1, 0);
	 
	}
	
}
