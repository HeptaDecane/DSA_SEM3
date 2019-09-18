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
int Stack::isOperator(char op){
	if(op=='^'||op=='*'||op=='/'||op=='+'||op=='-')
		return 1;
	else 
		return 0;
}
int Stack::precedence(char op){
	if(op=='^')
		return 3;
	else if(op=='*'||op=='/')
		return 2;
	else if(op=='+'||op=='-')
		return 1;
	else 
		return 0;
}
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
int main(){
	int j=0,len;
	Stack a;
	char symbol,top;
	string infix,postfix;
	cin>>infix;
	len=infix.length();
	infix[len]=')';
	postfix=infix;
	a.push('(');
	for(int i=0;infix[i]!=0;i++){
		symbol=infix[i];
		if(symbol=='('){
			a.push('(');
		}
		else if(symbol==')'&&!a.isEmpty()){
			while(a.peek()!='('){
				postfix[j]=a.peek();
				a.pop();
				j++;
			}
			a.pop();
		}
		else if(a.isOperator(symbol)){
			top=a.peek();
			if(a.precedence(top)<a.precedence(symbol))
				a.push(symbol);
			else{
				while(a.precedence(top)>=a.precedence(symbol)){
					postfix[j]=a.peek();
					a.pop();
					top=a.peek();
					j++;
				}
				a.push(symbol);
			}
		}
		else if(isalpha(symbol)||isdigit(symbol)){
			postfix[j]=symbol;
			j++;
		}
		else
		cout<<"Invalid";
	}
	for(;j<infix.length();j++)
		postfix[j]='\0';
	cout<<postfix;
	cout<<"\n";
	a.display();
	return 0;
}




