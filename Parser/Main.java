//Main class
//by Saoud Khalifah (s0832050)
//--------------------------------
//This class includes most of the binary tree building from
//the expressions.txt file in the local directory.
//The main function reads the text file of the expressions,
//and performs the infix to postfix conversion, adding
//nodes to a new binary tree.
//Note: Using paranthesis is essential to create a proper parse tree.
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Stack;


public class Main {

	/**
	 * @param args
	 */
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
	public static boolean precedence(String c1, String c2){
		int i1 = 0;
		int i2 = 0;
		if(c1.equals("+"))
			i1 = 1;
		else if(c1.equals("-"))
			i1 = 2;
		else if(c1.equals("*"))
			i1 = 3;
		else if(c1.equals("/"))
			i1 = 4;
		if(c2.equals("+"))
			i2 = 1;
		else if(c2.equals("-"))
			i2 = 2;
		else if(c2.equals("*"))
			i2 = 3;
		else if(c2.equals("/"))
			i2 = 4;
		if(i1 >= i2)
			return true;
		else
			return false;
	}
	public static String isParenthesis(String c){
		if(c.equals("("))
			return "(";
		else if(c.equals(")"))
			return ")";
		return "";
	}
	public static int p(char op)
	{
	    int p;
	    switch (op)
	    {
	        case '+' :
	        case '-' :
	             p = 1;
	             break;
	        case '*' :
	        case '/' :
	             p = 2;
	             break;
	        default:
	             p = 0;
	             break;
	    }
	    return p;

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	try{
		FileInputStream fstream = new FileInputStream("expressions.txt");
	    DataInputStream in = new DataInputStream(fstream);
	    BufferedReader br = new BufferedReader(new InputStreamReader(in));
	    String strLine;
		String conv[] = new String[50];
		LinkedBinaryTree<String> BT = new LinkedBinaryTree<String>();
		int iConv = 0;
	    while ((strLine = br.readLine()) != null)   {
	    	System.out.print(strLine + "\n");
	    	conv[iConv] = "";
	    	/*Infix to Prefix*/

	        Stack<String> s_1 = new Stack<String>();
	        Stack<String> s_2 = new Stack<String>();
	        char ar[] = strLine.toCharArray();
	        int len = ar.length;
	        for(int i = len - 1; i >= 0; i--)
	        {
	        	if(ar[i] == ' ')
	        		continue;
	            switch(ar[i])
	            {
	                case ')':
	                    s_1.push(String.valueOf(ar[i]));
	                    break;
	                case '(':
	                {
	                     while(!s_1.peek().equals(")"))
	                     {
	                         s_2.push(s_1.peek());
	                         s_1.pop();
	                     }
	                     s_1.pop();
	                     break;
	                }
	                case '+':  case '-':  case '*': case '/':
	                {
	                	if(s_1.size() == 0)
	                		s_1.push(String.valueOf(ar[i]));
	                	else{
	                    while(p(s_1.peek().charAt(0)) > p(ar[i]))
	                    {
	                        s_2.push(s_1.peek());
	                        s_1.pop();
	                    }
	                    s_1.push(String.valueOf(ar[i]));
	                	}
	                    break;
	                }
	                default:
	                {
	                    s_2.push(String.valueOf(ar[i]));
	                    break;
	                }
	            }

	        }
	        while(!s_1.empty())
	        {
	            s_2.push(s_1.peek());
	            s_1.pop();
	        }
	        while(!s_2.empty())
	        {
	            conv[iConv] += (s_2.peek());
	            s_2.pop();
	        }
	    	
	    	System.out.println("Prefix notation = " + conv[iConv]);
			for(int x = 0; x < conv[iConv].length(); x++){
				
				BT.addNode(conv[iConv].substring(x, x+1));
			}
			System.out.print("Height = " + BT.getHeight() + "\n");

			BT.BFS();
			iConv++;
			BT.destruct();
	    }
		
	}catch (Exception e){
	  System.err.println("Error: " + e.getMessage() + e.getCause());
	}
	}

}
