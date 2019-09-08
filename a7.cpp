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
	int peek(char);
	void free();
};

int Stack::isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}
int Stack::peek(char c){
	if(c==top->ch)
		return 1;
	else
		return 0;
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
	int rep=1;
	while(rep){
		Stack exp;
		string str;
		char top,ch;
		cout<<"\nEnter the Expression: ";
		cin>>str;
		int flag=1;
		if(str[0]=='}'||str[0]==')'||str[0]==']'){
			flag=0;
		}
		for(int i=0;str[i]!='\0';i++){
			if(str[i]=='{')
				exp.push(str[i]);
			else if(str[i]=='[')
				exp.push(str[i]);
			else if(str[i]=='(')
				exp.push(str[i]);
			if(!exp.isEmpty()){
				if(str[i]==')'&&exp.peek('('))
					exp.pop();
				else if(str[i]==')'&&!exp.peek('('))
					flag=0;
				if(str[i]=='}'&&exp.peek('{'))
					exp.pop();
				else if(str[i]=='}'&&!exp.peek('{'))
					flag=0;
				if(str[i]==']'&&exp.peek('['))
					exp.pop();
				else if(str[i]==']'&&!exp.peek('['))
					flag=0;
			}
			else if(exp.isEmpty()){
				if(str[i]=='}'||str[i]==')'||str[i]==']'){
					flag=0;
					break;
				}
			}
		}
		if(flag==1&&exp.isEmpty()==1)
			cout<<"\n--->Expression is well Paranthised";
		else
			cout<<"\n--->Expression is not Well Paranthised";
		cout<<"\n----------------------------------------------------------------------------";
		exp.free();
		str[0]='\0';
		cout<<"\nDo You Want to Check Another Expression? (0/1): ";
		cin>>rep;
	}
	cout<<"\nEND...";
	return 0;
}













