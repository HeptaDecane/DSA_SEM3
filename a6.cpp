//============================================================================
// Name        : Assignment.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
class Node{
	int roll;
	Node *next;
public:
	Node(int n){
		roll=n;
		next=NULL;
	}
	Node(){
		roll=0;
		next=NULL;
	}
	friend class List;
};
class List{
	Node *start;
public:
	void createList();
	void insert(int);
	void display();
	List(){
		start=NULL;
	}
};
void List::insert(int n){
	Node *temp,*t;
	temp=new Node(n);
	t=start;
	if(t==NULL){
		start=temp;
		temp->next=NULL;
	}
	else{
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=temp;
		temp->next=NULL;
	}
}
void List::createList(){
	int n,roll;
	cout<<"\nEnter No. of Students: ";
	cin>>n;
	cout<<"\nEnter Roll Numbers: ";
	for(int i=0;i<n;i++){
		cin>>roll;
		insert(roll);
	}
}
void List::display(){
	Node *t=start;
	cout<<"{";
	while(t!=NULL){
		cout<<t->roll<<" ";
		t=t->next;
	}
	cout<<"}";
}
int main(){
	List universal,flavour1,flavour2;
	universal.createList();
	universal.display();
	flavour1.createList();
	flavour1.display();
	flavour2.createList();
	flavour2.display();
	return 0;
}
