//============================================================================
// Name        : Assignment6B.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
	float coefficient;
	int exponent;
	Node* link;
public:
	Node(){
		coefficient=0;
		exponent=0;
		link=NULL;
	}
	Node(float,int);
	friend class List;
};
Node::Node(float coe,int exp){
	coefficient=coe;
	exponent=exp;
	link=NULL;
}
class List{
	Node *head;
public:
	List(){
		head=new Node();
		head->link=head;
	}
	void insert(float,int);
	void display();
	void getPolynomial();
	void arrange();
	float evaluate(float);
	void menu();
	void free();
	List add(List);
};
void List::free(){
	head->link=head;
}
void List::menu(){
	cout<<"\n-----------------------MENU----------------------------";
	cout<<"\n\tPress 1: Enter Polynomial";
	cout<<"\n\tPress 2: Display Polynomial";
	cout<<"\n\tPress 3: Evaluate Polynomial at x";
	cout<<"\n\tPress 4: Add Another Polynomial";
	cout<<"\n\tPress 9: Show Menu";
	cout<<"\n-------------------------------------------------------\n";
}
List List::add(List exp2){
	List e;
	Node *p,*q;
	float coe;
	int exp;
	p=head->link;
	q=exp2.head->link;
	for(;p!=head && q!=exp2.head;){
		if((p->exponent)>(q->exponent)){
			coe=p->coefficient;
			exp=p->exponent;
			e.insert(coe,exp);
			p=p->link;
		}
		else if((p->exponent)<(q->exponent)){
			coe=q->coefficient;
			exp=q->exponent;
			e.insert(coe,exp);
			q=q->link;
		}
		else{
			coe=p->coefficient+q->coefficient;
			exp=p->exponent;
			if(coe)
				e.insert(coe,exp);
			p=p->link;
			q=q->link;
		}
	}
	for(;p!=head;p=p->link){
		coe=p->coefficient;
		exp=p->exponent;
		e.insert(coe,exp);
	}
	for(;q!=exp2.head;q=q->link){
		coe=q->coefficient;
		exp=q->exponent;
		e.insert(coe,exp);
	}
	return e;
}
float List::evaluate(float x){
	float sum=0;
	int exp;
	float coe;
	Node *ptr;
	ptr=head->link;
	while(ptr!=head){
		coe=ptr->coefficient;
		exp=ptr->exponent;
		sum=sum+coe*pow(x,exp);
		ptr=ptr->link;
	}
	return sum;
}
void List::getPolynomial(){
	int exp,n;
	float coe;
	cout<<"\nEnter Number of Terms: ";
	cin>>n;
	cout<<"Enter Terms in as: Coefficient <space> Exponent\n";
	for(int i=0;i<n;i++){
		cout<<"Term "<<i+1<<": ";
		cin>>coe>>exp;
		insert(coe,exp);
	}
	arrange();
	return;
}
void List::insert(float coe,int exp){
	Node *temp,*t;
	temp=new Node(coe,exp);
	if(head->link==head){
		head->link=temp;
		temp->link=head;
		return;
	}
	t=head;
	while(t->link!=head){
		t=t->link;
	}
	t->link=temp;
	temp->link=head;
	return;
}
void List::display(){
	Node *t;
	t=head->link;
	if(head->link==head){
		cout<<"\nList is Empty";
		return;
	}
	while(t!=head){
		if(t->exponent){
			if(t->coefficient>0){
				cout<<" + "<<t->coefficient<<"x^"<<t->exponent;
			}
			else{
				cout<<" - "<<-t->coefficient<<"x^"<<t->exponent;
			}
		}
		else{
			if(t->coefficient>0){
				cout<<" + "<<t->coefficient;
			}
			else{
				cout<<" - "<<-t->coefficient;
			}
		}
		t=t->link;
	}
	return;
}
void List::arrange(){
	int exp;
	float coe;
	Node *p,*q;
	for(p=head->link;p!=head;p=p->link){
		for(q=p->link;q!=head;q=q->link){
			if(p->exponent<q->exponent){
				exp=p->exponent;
				coe=p->coefficient;
				
				p->exponent=q->exponent;
				p->coefficient=q->coefficient;
				
				q->exponent=exp;
				q->coefficient=coe;
			}
		}
	}
}
int main() {
	int ch=1;
	List exp1,exp2,sum;
	float x;
	exp1.menu();
	while(ch){
		switch(ch){
			case 1:	cout<<"Enter Experssion:";
					exp1.free();
					exp1.getPolynomial();
					break;
			case 2: cout<<"\nP(x) =";
					exp1.display();
					break;
			case 3: cout<<"\nEnter Evaluation Value: ";cin>>x;
					cout<<"p("<<x<<") = "<<exp1.evaluate(x);
					break;
			case 4: cout<<"Enter 2nd Experssion:";
					exp2.getPolynomial();
					sum=exp1.add(exp2);
					cout<<"\n(";exp1.display();cout<<" ) + (";exp2.display();cout<<" )\n";
					cout<<"\t\t=";sum.display();
					break;
			case 9: exp1.menu();
					break;
			default: cout<<"\n Enter Valid Choice!";
		}
		cout<<"\n-------------------------------------------------------";
		cout<<"\nEnter Choice [0-exit]: ";cin>>ch;
	}
	cout<<"\nEND...";
	return 0;
}
