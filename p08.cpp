#include<bits/stdc++.h>
using namespace std;
#define MAX 256
template<typename T>
class Stack{
	T arr[MAX];
	int top;
public:
	Stack(){
		top=-1;
	}
	
	bool push(T key){
		top++;
		if(top<MAX){
			arr[top]=key;
			return true;
		}
		cout<<"\nStack Full!";
		top--;
		return false;
	}
	
	T peek(){
		if(top==-1)
			return '#';
		return arr[top];
	}
	
	bool pop(){
		if(top==-1){
			cout<<"\nStack Empty!";
			return false;
		}
		top--;
	}
	
	void display(){
		for(int i=top;i>=0;i--)
			cout<<"\n"<<arr[i];
	}
	
	bool isEmpty(){
		return top==-1;
	}
	
	bool isFull(){
		return top==MAX-1;
	}
	
	~Stack(){
		top=-1;
	}
};

class Expression{
	char str[256];
public:
	Expression();
	void read();
	void display();
	void append(char);
	int length();
	int inPrecedence(char);
	int outPrecedence(char);
	bool isOperator(char);
	float evaluate();
	Expression infixToPostfix();
	~Expression();
};
Expression::Expression(){
	str[0]='\0';
}
Expression::~Expression(){
	str[0]='\0';
}
void Expression::read(){
	cout<<"\n Enter infix Expression (without space): ";
	cin>>str;
}
void Expression::display(){
	cout<<str;
}
int Expression::length(){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}
void Expression::append(char end){
	int i;
	for(i=0;str[i]!='\0';i++);
	str[i]=end;
	str[i+1]='\0';
}
bool Expression::isOperator(char key){
	return (key=='^'||key=='/'||key=='*'||key=='-'||key=='+');
}
int Expression::inPrecedence(char op){
	if(op=='^')
		return 3;
	else if(op=='/'||op=='*')
		return 2;
	else if(op=='+'||op=='-')
		return 1;
	else
		return 0;
}
int Expression::outPrecedence(char op){
	if(op=='^')
		return 4;
	else if(op=='/'||op=='*')
		return 2;
	else if(op=='+'||op=='-')
		return 1;
	else
		return 0;
}
Expression Expression::infixToPostfix(){
	Stack<char> s;
	Expression exp;
	s.push('(');
	this->append(')');
	char current,top;
	for(int i=0;this->str[i]!='\0';i++){
		current=this->str[i];
		if(current=='(')
			s.push(current);
		else if(current==')'){
			while(s.peek()!='('){
				if(s.isEmpty()){
					exp.str[0]='\0';
					return exp;
				}
				top=s.peek();
				exp.append(top);
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(current)){
			if(s.isEmpty()){
				exp.str[0]='\0';
				return exp;
			}
			top=s.peek();
			if(inPrecedence(top)<outPrecedence(current))
				s.push(current);
			else{
				while(inPrecedence(top)>=outPrecedence(current)){
					exp.append(top);
					s.pop();
					if(s.isEmpty()){
						exp.str[0]='\0';
						return exp;
					}
					top=s.peek();
				}
				s.push(current);
			}		
		}
		else if(isalpha(current)||isdigit(current))
			exp.append(current);
		else{
			exp.str[0]='\0';
			return exp;
		}
	}
	s.display();
	if(!s.isEmpty()){
		exp.str[0]='\0';
		return exp;
	}
	return exp;
}
float Expression::evaluate(){
	Stack<float> s;
	char current,top;
	float a,b;
	for(int i=0;this->str[i]!='\0';i++){
		current=this->str[i];
		if(isalpha(current)){
			cout<<"\nEnter Value of "<<current<<": ";
			cin>>a;
			s.push(a);
		}
		else if(isdigit(current)){
			a=current-'0';
			s.push(a);
		}
		else if(isOperator(current)){
			if(s.isEmpty()){
				cout<<"*Undefined*";
				cout<<"\n*Operator(s) MisMatch-";
				return 0;
			}
			b=s.peek();
			s.pop();
			if(s.isEmpty()){
				cout<<"*Undefined*";
				cout<<"\n*Operator(s) MisMatch-";
				return 0;
			}
			a=s.peek();
			s.pop();
			switch(current){
				case '+':	s.push(a+b);
							break;
				case '-':	s.push(a-b);
							break;
				case '*':	s.push(a*b);
							break;
				case '/':	s.push(a/b);
							break;
				case '^':	s.push(pow(a,b));
							break;
			}
		}
		else{
			cout<<"*Undefined*";
			cout<<"\n*Operator(s) MisMatch-";
			return 0;
		}
	}
	return s.peek();
}
int main(){
	Expression infix,postfix;
	int rep=1;
	while(rep){
		infix.read();
		postfix=infix.infixToPostfix();
		if(postfix.length()){
			cout<<"Postfix Expression is: ";
			postfix.display();
			cout<<"\n\nEvaluation: ";
			cout<<"\n";
			cout<<postfix.evaluate();
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





