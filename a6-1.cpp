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
	void sort();
	void remove(int);
	void free();
	int count();
	List _minus(List);
	List _union(List);
	List _intersection(List);
	List(){
		start=NULL;
	}
};
List List::_minus(List a){
	List only;
	for(Node *p=start;p!=NULL;p=p->next){
		only.insert(p->roll);
	}
	for(Node *p=only.start;p!=NULL;p=p->next){
		for(Node *q=a.start;q!=NULL;q=q->next){
			if(p->roll==q->roll){
				only.remove(q->roll);
			}
		}
	}
	return only;
}
void List::sort(){
	int temp;
	for(Node* p=start;p!=NULL;p=p->next){
		for(Node* q=p->next;q!=NULL;q=q->next){
			if(p->roll>q->roll){
				temp=p->roll;
				p->roll=q->roll;
				q->roll=temp;
			}
		}
	}
	
}
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
	cout<<"Enter Roll Numbers: ";
	for(int i=0;i<n;i++){
		cin>>roll;
		insert(roll);
	}
}
int List::count(){
	int count=0;
	for(Node *p=start;p!=NULL;p=p->next){
		count++;
	}
	return count;
}
void List::remove(int n){
	Node* p=start,*t,*temp;
	if(start->roll==n){
		start=start->next;
		return;
	}
	while(p->next->roll!=n){
		p=p->next;
	}
	p->next=p->next->next;
	return;
}
List List::_union(List a){
	int flag=1;
	List uni;
	for(Node* p=a.start;p!=NULL;p=p->next){
		uni.insert(p->roll);
	}
	for(Node* p=start;p!=NULL;p=p->next){
		flag=1;
		for(Node* q=uni.start;q!=NULL;q=q->next){
			if(p->roll==q->roll){
				flag=0;
			}
		}
		if(flag){
			uni.insert(p->roll);
		}
	}
	return uni;
}
List List::_intersection(List a){
	int flag=0;
	List intr;
	for(Node* p=start;p!=NULL;p=p->next){
		for(Node* q=a.start;q!=NULL;q=q->next){
			if(p->roll==q->roll)
				intr.insert(q->roll);
		}		
	}
	return intr;
}
void List::display(){
	Node *t=start;
	cout<<"   Set: { ";
	while(t!=NULL){
		cout<<t->roll<<" ";
		t=t->next;
	}
	cout<<"}";
} 
void List::free(){
	start=NULL;
	delete start;
}
int main(){
	int ch=1,universe,err;
	List flavour1,flavour2,uni,intr,f1,f2;
	while(ch){
		tryagain:
		flavour1.free();
		flavour2.free();
		uni.free();
		intr.free();
		f1.free();
		f2.free();
		cout<<"\n---------------------------------SURVEY ENTRY-------------------------------------\n";
		cout<<"Enter the Total No. of students Surveyed: ";
		cin>>universe;
		cout<<"\n--->VANILLA FLAVOUR:";
		flavour1.createList();
		cout<<"\n--->BUTTERSCOTCH FLAVOUR:";
		flavour2.createList();
		uni=flavour1._union(flavour2);
		if(universe<uni.count()){
			cerr<<"\nError: Invalid Statistics";
			cout<<"\nDesc: Distinct Participants Count Exceeded the Universal Count";
			cout<<"\nSoln: Enter (1) to Try Again: ";cin>>err;
			if(err==1)
				goto tryagain;
			else
				return 0;
		}
		else{
			flavour1.sort();
			flavour2.sort();
			uni.sort();
			intr=flavour1._intersection(flavour2);
    		intr.sort();
    		f1=flavour1._minus(flavour2);
    		f1.sort();
    		f2=flavour2._minus(flavour1);
	    	f2.sort();
   		 	cout<<"\n-------------------------------SURVEY ANALYSIS------------------------------------\n";
   		 	cout<<"\n1) No. of Students Liking Vanilla Flavour: "<<flavour1.count()<<"\n";
			flavour1.display();
    		cout<<"\n\n2) No. of Students liking ButterScotch Flavour: "<<flavour2.count()<<"\n";
			flavour2.display();
			cout<<"\n\n3) No. of Students Liking both the Flavours: "<<intr.count()<<"\n";
			intr.display();
			cout<<"\n\n4) No. of Students Liking Atleast One of the Two Flavours: "<<uni.count()<<"\n";
			uni.display();
			cout<<"\n\n5) No. of Students Liking only Vanilla Flavour: "<<f1.count()<<"\n";
			f1.display();
			cout<<"\n\n6) No. of Students Liking only ButterScotch Flavour: "<<f2.count()<<"\n";
			f2.display();		
			cout<<"\n\n7) No. of Students Liking Neither of the Two Flavours: "<<universe-uni.count();
			cout<<"\n----------------------------------------------------------------------------------";
			cout<<"\n\n Do You Want to Analyse Another Survey? (0/1): ";
			cin>>ch;
		}
	}
	return 0;
} 
