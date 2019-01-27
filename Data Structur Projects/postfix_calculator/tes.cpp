#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <istream>

using namespace std;




bool is_operator(char c){
    if(c == '+' || c == '-' || c == '*' || c =='/'){
        return true;
    }
    return false;
}

int calculate(int n, int m, char op){
    if(op == '+'){
        return n + m;
    }
    else if(op == '-'){
        return m - n;
    }
    else if(op == '*'){
        return n*m;
    }
    else if(op == '/'){
        return m/n;
    }
    return 0;
}

string expr;
char buffer[1000];
int main(){
    int n, m, len, j, x;
    stack<int> s;
    cout << "Enter a Postfix Expression :: ";
    getline(cin,expr);
    cout << endl;
    len = expr.length();
    j=0;
    for(int i = 0; i<len;i++){
        
        if(expr[i]>='0' && expr[i]<='9'){
            buffer[j++]=expr[i];
        }
        else if(expr[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }
        else if(is_operator(expr[i])){
            n = s.top();
            s.pop();
            m = s.top();
            s.pop();
            s.push(calculate(n,m,expr[i]));
        }
    }
    cout << "The answer is :: " << s.top() << endl;
    
    return 0;
}