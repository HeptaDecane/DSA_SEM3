//============================================================================
// Name        : MockTest.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define MAX 256
template<class T>
class Stack{
	T arr[MAX];
	int top;
public:
	Stack(){
		top=-1;
	}
	
	
	void push(T a){
		top++;
		if(top<MAX)
			arr[top]=a;
		else{
			cout<<"Stack is FULL";
			top--;
		}	
	}
	T peek(){
		if(top==-1)
			return '#';
		return arr[top];
	}
	
	
	void pop(){
		if(top==-1){
			cout<<"*Undefined*";
			cout<<"\n*Operator(s) Mismatch";
			return;
		}
		top--;
	}
	
	
	bool isEmpty(){
		return top==-1;
	}
	
	
	bool isFull(){
		return top==MAX;
	}
	
	
	void display(){
		for(int i=top;i>=0;i--)
			cout<<arr[i]<<" ";
	}
	
	
	~Stack(){
		top=-1;
	}
};




class Expression{
	char str[256];
public:
	Expression(){
		str[0]='\0';
	}
	void read();
	void display();
	bool isValid();
	void append(char);
	int getLength();
	int precedence(char);
	int isOperator(char);
	float evaluate();
	Expression infixToPostfix();
	~Expression(){
		str[0]='\0';
	}
};
int Expression::getLength(){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}
void Expression::read(){
	cout<<"\nEnter Infix Expression (without space): ";
	cin>>str;
}
void Expression::display(){
	cout<<str;
}
void Expression::append(char c){
	int i;
	for(i=0;str[i]!=0;i++);
	str[i]=c;
	str[i+1]='\0';
}
int Expression::isOperator(char op){
	if(op=='^'||op=='*'||op=='/'||op=='+'||op=='-')
		return 1;
	else
		return 0;
}
int Expression::precedence(char op){
	if(op=='^')
		return 3;
	else if(op=='*'||op=='/')
		return 2;
	else if(op=='+'||op=='-')
		return 1;
	else
		return 0;
}
bool Expression::isValid(){
	Stack<char> s;
	if(str[0]=='}'||str[0]==')'||str[0]==']'){
		return 0;
	}
	for(int i=0;str[i]!='\0';i++){
		if(str[i]=='{')
			s.push(str[i]);
		else if(str[i]=='[')
			s.push(str[i]);
		else if(str[i]=='(')
			s.push(str[i]);
		if(!s.isEmpty()){
			if(str[i]==')'&&s.peek()=='(')
				s.pop();
			else if(str[i]==')'&&s.peek()!='(')
				return 0;
			if(str[i]=='}'&&s.peek()=='{')
				s.pop();
			else if(str[i]=='}'&&s.peek()!='{')
				return 0;
			if(str[i]==']'&&s.peek()=='[')
				s.pop();
			else if(str[i]==']'&&s.peek()!='[')
				return 0;
		}
		else if(s.isEmpty()){
			if(str[i]=='}'||str[i]==')'||str[i]==']'){
				return 0;
				break;
			}
		}
	}
	if(s.isEmpty())
		return 1;
	else
		return 0;
}
Expression Expression::infixToPostfix(){
	Stack<char> s;
	char symbol,top;
	Expression exp;
	s.push('(');
	str[getLength()]=')';
	for(int i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(symbol=='('){
			s.push('(');
		}
		else if(symbol==')'&&!s.isEmpty()){
			while(s.peek()!='('){
				exp.append(s.peek());
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(symbol)){
			top=s.peek();
			if(precedence(top)<precedence(symbol))
				s.push(symbol);
			else{
				while(precedence(top)>=precedence(symbol)){
					exp.append(s.peek());
					s.pop();
					top=s.peek();
				}
				s.push(symbol);
			}
		}
		else if(isalpha(symbol)||isdigit(symbol)){
			exp.append(symbol);
		}
		else{
			exp.str[0]='\0';
			break;
		}
	}
	if(!s.isEmpty()){
		exp.str[0]='\0';
	}
	return exp;
}
float Expression::evaluate(){
	Stack<float> s;
	char symbol,top;
	float a,b;
	for(int i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(isalpha(symbol)){
			cout<<"*Undefined*";
			cout<<"\n*Ambiguity in Variables!";
			return 0;
		}
		else if(isdigit(symbol)){
			a=symbol-'0';
			s.push(a);
		}
		else if(isOperator(symbol)){
			b=s.peek();
			s.pop();
			a=s.peek();
			s.pop();
			switch(symbol){
				case '+': s.push(a+b);
							break;
				case '-': s.push(a-b);
							break;
				case '*': s.push(a*b);
							break;
				case '/': s.push(a/b);
							break;
			}
		}
	}
	s.display();
	return 0;
}
int main(){
	Expression infix,postfix;
	int rep=1;
	float val;
	while(rep){
		infix.read();
		postfix=infix.infixToPostfix();
		if(postfix.getLength()){
			cout<<"Postfix Expression is: ";
			postfix.display();
			cout<<"\nEvaluation: ";
			cout<<"\n";
			infix.display();cout<<"\b = ";postfix.evaluate();
			
		}
		else
			cout<<"\nInvalid Infix Expression!";
		cout<<"\n\n---------------------------------------------------------";
		cout<<"\nDo You Want to Enter Another Expression(0/1): ";
		cin>>rep;
	}
	cout<<"\n--------------------------END----------------------------\n";
	return 0;
}
