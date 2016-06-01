#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include "BinaryExpressionTree.h"

using namespace std;

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

string removeSpaces(string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

int main()
{
    try{
        string expresion;
        cout<<"Enter a expression:"<<endl;
        getline(cin, expresion);
        BinaryExpressionTree<string> *BT = new BinaryExpressionTree<string>();
		string conv;
		if (!expresion.empty())
        {
            cout<<endl;
            conv = "";
            //Infix to Prefix
            stack<string> s_1;
	        stack<string> s_2;
	        vector<char> *expr = new vector<char>(expresion.begin(), expresion.end());
	        for_each(expr->rbegin(),expr->rend(),[&s_1, &s_2](char n){
                  //cout<<string(1,n)<<endl;
                if (n==' '){
                        //cout<<"is space, ignore"<<endl;
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
                else
                {
                    s_2.push(string(1,n));
                }
            });
            while(!s_1.empty())
	        {
	            //cout<<s_1.top()<<endl;
	            s_2.push(s_1.top());
	            s_1.pop();
	        }
	        while(!s_2.empty())
	        {
	            conv += (s_2.top());
	            s_2.pop();
	        }
	        cout<<"-----------------------";
	        cout<<conv;
	        cout<<"-----------------------";
            cout<<endl<<"Prefix notation = "<<conv;
			for(int x = 0; x < conv.length(); x++){
                string *newNode = new string(conv.substr(x, x+1));
				BT->addNode(newNode);
			}
			cout<<endl<<"Height= "<<BT->getHeight()<<endl;
			BT->BFS(); //fix error here
			BT->destruct();
	    }
	}catch (exception& e){
	    cout<<"Error:"<<e.what() << endl;
	}
    return 0;

}


