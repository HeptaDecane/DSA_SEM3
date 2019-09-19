//============================================================================
// Name        : MockTest.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
class Node{
	char ch;
	Node* link;
public:
	Node(char);
	friend class Stack;
};
Node::Node(char c){
	ch=c;
	link=NULL;
}
class Stack{
	Node *top;
public:
	Stack(){
		top=NULL;
	}
	int push(char);
	int pop();
	int isEmpty();
	void display();
	char peek();
	void free();
	int precedence(char);
	int isOperator(char);
};
int Stack::isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}
char Stack::peek(){
	if(top==NULL)
		return '#';
	return top->ch;
}
void Stack::display(){
	Node* ptr=top;
	if(top==NULL){
		cout<<"\n#";
		return;
	}
	while(ptr!=NULL){
		cout<<ptr->ch<<" ";
		ptr=ptr->link;
	}
	cout<<"\n";
}
int Stack::push(char c){
	Node* temp;
	temp=new Node(c);
	temp->link=top;
	top=temp;
	return 1;
}
int Stack::pop(){
	Node* temp;
	if(top==NULL){
		cout<<"\n#";
		return 0;
	}
	else{
		temp=top;
		top=top->link;
		delete temp;
		return 1;
	}
}
void Stack::free(){
	top=NULL;
}

class Expression{
	string str;
public:
	void read(string);
	void display();
	bool isValid();
	int getLength();
	int precedence(char);
	int isOperator(char);
	Expression infixToPostfix();
};
int Expression::getLength(){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}
void Expression::read(string exp){
	str=exp;
}
void Expression::display(){
	cout<<"\n"<<str;
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
	Stack s;
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
	Stack s;
	char symbol,top;
	int j=0,len;
	string postfix;
	Expression exp;
	len=str.length();
	str[len]=')';
	postfix=str;
	s.push('(');
	for(int i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(symbol=='('){
			s.push('(');
		}
		else if(symbol==')'&&!s.isEmpty()){
			while(s.peek()!='('){
				postfix[j]=s.peek();
				s.pop();
				j++;
			}
			s.pop();
		}
		else if(isOperator(symbol)){
			top=s.peek();
			if(precedence(top)<precedence(symbol))
				s.push(symbol);
			else{
				while(precedence(top)>=precedence(symbol)){
					postfix[j]=s.peek();
					s.pop();
					top=s.peek();
					j++;
				}
				s.push(symbol);
			}
		}
		else if(isalpha(symbol)||isdigit(symbol)){
			postfix[j]=symbol;
			j++;
		}
		else
			return exp;
	}
	for(;j<str.length();j++)
		postfix[j]='\0';
	if(!s.isEmpty())
		return exp;
	exp.read(postfix);
	return exp;
}
int main(){
	Expression infix,postfix;
	string exp;
	cin>>exp;
	infix.read(exp);
	postfix=infix.infixToPostfix();
	if(postfix.getLength())
		postfix.display();
	else
		cout<<"\nInvalid Expression";
	return 0;
}
