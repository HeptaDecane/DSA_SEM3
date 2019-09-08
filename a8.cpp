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
		cout<<"\nStack is Empty";
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
		cout<<"\nStack is Empty";
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
	Stack a;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	cout<<a.peek()<<"\n";
	a.pop();
	cout<<a.peek()<<"\n";
	a.pop();
	cout<<a.peek()<<"\n";
	a.pop();
	cout<<a.peek()<<"\n";
	a.pop();
	cout<<a.peek()<<"\n";
	a.pop();
	cout<<a.peek()<<"\n";
	return 0;
}




