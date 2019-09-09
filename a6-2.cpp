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
	float evaluate(float);
	List add(List);
};
/*Under Construction*/
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
		}
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
	cout<<"Enter Terms in order [Coefficient< >Exponent]\n";
	for(int i=0;i<n;i++){
		cout<<"Term "<<i+1<<": ";
		cin>>coe>>exp;
		insert(coe,exp);
	}
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
		cout<<"\n"<<t->coefficient<<" "<<t->exponent;
		t=t->link;
	}
	return;
}
int main() {
	List a,b;
	float x;
	a.getPolynomial();
	a.display();
}
