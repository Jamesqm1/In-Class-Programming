/*
	postfix_calculator.cpp

	Implementation of the postfix calculator. 

    CSCI 262, Spring 2018, Project 2

	author: 
*/

#include "postfix_calculator.h"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

	// TODO: Implement as per postfix_calculator.h
bool postfix_calculator::evaluate(string expr) {
	istringstream iss (expr);
	while(!iss.eof()){
		string next;
		iss >> next;
		if(next.length()==1 && is_operator(next[0])){ 
			if(calculator_stack.size()<=1){
				return false;
			}
			p = &next[0];
			
			n = calculator_stack.top();
			calculator_stack.pop();
			m = calculator_stack.top();
			calculator_stack.pop();
			calculator_stack.push(calc(n,m,p));
		}
		else if(next.length()>=1 && is_function(next[0])){
			if(calculator_stack.empty()){
				return false;
			}
			p = &next[0];
			n = calculator_stack.top();
			calculator_stack.pop();
			calculator_stack.push(calc(n,p));
		}
		else if(next[0]>='0' && next[0]<='9' || next[0]=='-'){
			double t = stod(next);
			calculator_stack.push(t);
		}
	}
	return true;
}
	// Read the comments in postfix_calculator.h for this
	// method first!  That is your guide to the required
	// functioning of this method.
	//
	// There are various ways to parse expr.  I suggest
	// you create an istringstream object, constructed on
	// expr:
	// 	istringstream string_in(expr);
	// Then you can get each substring from expr using >>.
    //
    // Check each substring first to see if you have one of 
    // the four operators; if not, you can assume the value
    // is a number that you can convert to a double.  (This
    // may not be a good assumption - but we won't test you
    // on robustly handling anything other than numbers and
    // operatorcalculator_stack.)  You can use the stod() function in the
    // string library to convert strings to doublecalculator_stack.



// TODO: Implement the remaining functions specified
// in postfix_calculator.h.
//
// You should start by creating "stubs" for each of
// the methods - these are methods that do nothing
// except return a value if needed.  For example, the 
// evaluate() method above does nothing but return true.
//
// Once you've got stubs for everything, then you should
// be able to compile and test the user interface.  Then
// start implementing functions, *testing constantly*!



	
void postfix_calculator::clear(){
	while(!calculator_stack.empty()){
		calculator_stack.pop();
	}
}


double postfix_calculator::top(){
	if(calculator_stack.empty()){
		return 0.0;
	}
	return calculator_stack.top();
}


std::string postfix_calculator::to_string(){
	string output = "";
	if(calculator_stack.empty()){
		return "0.0";
	}
	stack<double> n;
	n = calculator_stack;
	while(!calculator_stack.empty()){
		output += std::to_string(calculator_stack.top())+" ";
		calculator_stack.pop();
	}
	calculator_stack = n;
	return output;
}

postfix_calculator::postfix_calculator(){
	expr="";
	clear();
	
}

bool postfix_calculator::is_operator(char c){
    if(c == '+' || c == '-' || c == '*' || c =='/' || c=='^'){
        return true;
    }
    return false;
}

bool postfix_calculator::is_function(char c){
	if( c =='l' || c == 's' || c == 't' || c =='c' || c=='a' || c =='e' || c == '!' ){
		return true;
	}
	return false;
	
}

double postfix_calculator::calc(double a, double b, char *op){
	if(*op == '+'){
        return a + b;
    }
    else if(*op == '-'){
        return b - a;
    }
    else if(*op == '*'){
        return b*a;
    }
    else if(*op == '/'){
        return b/a;
    }
    else if(*op == '^'){
    	return pow(b,a);
    }
    return 0;
}

double postfix_calculator::calc(double a, char *op){
	if(*op =='t'){
		return tan(a);
	}
	else if(*op =='c'){
		if(*(op+1)=='b'){
			return cbrt(a);
		}
		return cos(a);
	}
	else if(*op == 'l'){
		if(*(op+1)=='n'){
    		return log(a);
    	}
    	else if(*(op+3)=='1'){
    		return log10(a);
    	}
    	else if (*(op+3)=='2'){
    		return log2(a);
    	}
	}
	else if(*op == 's'){
		if(*(op+1) == 'i'){
    		return sin(a);
    	}
    	else if(*(op+1)=='q'){
    		return sqrt(a);
    	}
	}
	else if(*op == 'a'){
		if(*(op+1)=='s'){
			return asin(a);
		}
		else if(*(op+1)=='c'){
			return acos(a);
		}
		else if(*(op+1)=='t'){
			return atan(a);
		}
		else if(*(op+1)=='b'){
			return abs(a);
		}
		
	}
	else if(*op=='e'){
		if(*(op+3)=='2'){
			return exp2(a);
		}
		return exp(a);
	}
	else if (*op == '!'){
		a = floor(a);
		if(a<0){
			return 0;
		}
		else if(a==0 || a==1){
			return 1;
		}
		else if(a>1){
			for(int i =a-1;i>=1;i--){
				a*=i;
			}
			return a;
		}
	}
	return 0.0;
}


