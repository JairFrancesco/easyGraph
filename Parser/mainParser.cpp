#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include "BinaryExpressionTree.h"

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

int main()
{
    try{
        string expresion;
        cout<<"Enter a expression:"<<endl;
        cin>>expresion;
        BinaryExpressionTree<string> *BT = new BinaryExpressionTree<string>();
		string conv[50];
		int iConv = 0;
		if (!expresion.empty())
        {
            cout<<endl;
            conv[iConv] = "";
            /*Infix to Prefix*/
            stack<string> s_1;
	        stack<string> s_2;
	        vector<char> *expr = new vector<char>(expresion.begin(), expresion.end());
	        for_each(expr->rbegin(),expr->rend(),[&s_1, &s_2](char n){
                  //cout<<string(1,n)<<endl;
                if (n==' '){
                }
                else if (n==')'){
                    s_1.push(string(1,n));
                }
                else if (n=='('){
                    while(!s_1.top().compare(")")==0){
                        s_2.push(s_1.top());
                        s_1.pop();
                    }
                    s_1.pop();
                }
                else if (n=='+' || n=='-' || n=='*' || n=='/'){
                    if(s_1.size() == 0)
	                		s_1.push(string(1,n));
                    else{
                        while(p(s_1.top().at(0)) > p(n))
                        {
                            s_2.push(s_1.top());
                            s_1.pop();
                        }
                        s_1.push(string(1,n));
                    }
                }
            });
            while(!s_1.empty())
	        {
	            s_2.push(s_1.top());
	            s_1.pop();
	        }
	        while(!s_2.empty())
	        {
	            conv[iConv] += (s_2.top());
	            s_2.pop();
	        }
            cout<<endl<<"Prefix notation = "<<conv[iConv];
			for(int x = 0; x < conv[iConv].length(); x++){
                string *node = new string(conv[iConv].substr(x, x+1));
				BT->addNode(node);
			}
			cout<<endl<<"Height= "<<BT->getHeight()<<endl;
			BT->BFS();
			iConv++;
			BT->destruct();
	    }
	}catch (exception& e){
	    cout<<"Error:"<<e.what() << endl;
	}
    return 0;

}


