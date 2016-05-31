#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;


string isOperator(string c){
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

bool precedence(string c1, string c2){
        int i1 = 0;
        int i2 = 0;
        if(c1.compare("+") == 0)
            i1 = 1;
        else if(c1.compare("-") == 0)
            i1 = 2;
        else if(c1.compare("*") == 0)
            i1 = 3;
        else if(c1.compare("/") == 0)
            i1 = 4;
        if(c2.compare("+") == 0)
            i2 = 1;
        else if(c2.compare("-") == 0)
            i2 = 2;
        else if(c2.compare("*") == 0)
            i2 = 3;
        else if(c2.compare("/") == 0)
            i2 = 4;
        if(i1 >= i2)
            return true;
        else
            return false;
}


string isParenthesis(string c){
        if(c.compare("(")==0)
            return "(";
        else if(c.compare(")")==0)
            return ")";
        return "";
}
int p(char op)
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




double string_to_double(std::string strg){
    if(strg=="x"){
        double x;
        return x;
    }
    else{
        double num;
        std::stringstream stream;
        stream << strg;
        stream >> num;
        return num;
    }

}


int main()
{
    try{
        string expresion;
        cin>>s;
        LinkedBinaryTree *BT = new LinkedBinaryTree<string>();
		//FileInputStream fstream = new FileInputStream("expressions.txt");
	    //DataInputStream in = new DataInputStream(fstream);
	    //BufferedReader br = new BufferedReader(new InputStreamReader(in));
	    //String strLine;
		//String conv[] = new String[50];
		string conv[50];
		//LinkedBinaryTree<String> BT = new LinkedBinaryTree<String>();
		int iConv = 0;
		if (expresion!=NULL)
        {
            cout<<endl;
            conv[iConv] = "";
            /*Infix to Prefix*/
            stack<String> s_1 = new stack<String>();
	        stack<String> s_2 = new stack<String>();
	        int len = expresion.length();
	        for_each(expresion.begin(), expresion.end(), [](char &n){

                  });
        }
	    while ((strLine = br.readLine()) != null)   {
	    	System.out.print(strLine + "\n");
	    	conv[iConv] = "";
	    	/*Infix to Prefix*/

	        stack<String> s_1 = new stack<String>();
	        stack<String> s_2 = new stack<String>();
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

	}catch (exception& e){
	    cout<<"Error: " + e.what() << endl();
	}
    return 0;

}



