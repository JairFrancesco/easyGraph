This includes the following files:
-BTNode.java
-LinkedBinaryTree.java
-Main.java
-expressions.txt


(Main.java)
-----------------------------------------------
This class contains the main() function that creates
binary trees by parsing the expressions.txt file.
It is important that the expressions contain paranthesis, to
separate them appropriately on the binary tree.
The class also includes infix to postfix conversion.

(LinkedBinaryTree.java)
-----------------------------------------------
This class manages the binary tree correctly. It calculates the height and prints out a basic diagram of the tree on the console vertically.

(BTNode.java)
-----------------------------------------------
This class is the Node structure in the binary tree. It is basic and includes the left, right and data fields.

Auxiliar Code


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