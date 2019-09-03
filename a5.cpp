//============================================================================
// Name        : Assignment.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
	bool status;
	string name;
	Node *next;
	Node *prev;
public:
	Node();
	Node(bool,string);
	friend class List;
};
Node::Node(){
	status=0;
	name="NILL";
	next=NULL;
	prev=NULL;
}
class List{
	Node *start;
	Node *last;
public:
	List();
	void createRow();
	void insertLast();
	void displayRow(int);
	int occupy(int,string);
	int unoccupy(int,string);
	void display(List []);
	void create(List []);
	void menu();
	void book(List []);
	void cancel(List []);
	int seats(List []);
};
List::List(){
	start=NULL;
	last=NULL;
}
int List::seats(List row[10]){
	int count=0;
	for(int i=0;i<10;i++){
		Node *t=row[i].start;
		for(int j=0;j<7;j++){
			if(!t->status)
				count++;
			t=t->next;
		}
	}
	return count;
}
void List::create(List row[10]){
	for(int i=0;i<10;i++)
		row[i].createRow();
}
void List::display(List row[10]){
	int number=1;
	cout<<"\t ";
	for(int i=0;i<7;i++)
		cout<<"Col: "<<i+1<<"        ";
	cout<<endl;
	for(int i=0;i<10;i++){
		if(i<=8)
			cout<<"Row "<<i+1<<":  ";
		else
			cout<<"Row "<<i+1<<": ";
		row[i].displayRow(number);
		number+=7;
	}
	cout<<"# Available Seat(s): "<<seats(row);
}
void List::createRow(){
	for(int i=0;i<7;i++)
		insertLast();
}
void List::insertLast(){
	Node *temp=new Node();
    if (start == last && start == NULL)
    {
//        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }

}
void List::displayRow(int n){
    Node *t;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    t=start;
    for (int i=0;i<6;i++)
    {
        cout<<"|"<<t->status<<"|"<<t->name<<"|"<<n++<<"|   ";
        t = t->next;
    }
    cout<<"|"<<t->status<<"|"<<t->name<<"|"<<n++<<"|   "<<endl;
}
int List::occupy(int col,string _name){
	Node *t;
	t=start;
	for(int i=0;i<col;i++){
		t=t->next;
	}
	if(t->status){
			return 0;
	}
	t->status=1;
	t->name=_name;
	return 1;
}
int List::unoccupy(int col,string _name){
	Node *t;
	t=start;
	for(int i=0;i<col;i++){
		t=t->next;
	}
	if(t->status){
		if(t->name==_name){
			t->status=0;
			t->name="NILL";
			return 1;
		}
		return -1;		
	}
	return 0;
}
void List::menu(){
	cout<<"\n\n------------------CHECK YOUR SHOW--------------------"<<endl;
	cout<<"\tPress 1 : Display Seats"<<endl;
	cout<<"\tPress 2 : Book Ticket(s)"<<endl;
	cout<<"\tPress 3 : Cancel Ticket(s)"<<endl;
	cout<<"\tPress 0 to exit"<<endl;
}
void List::book(List row[10]){
	int n,seatNo,r,c;
	string name;
	cout<<"Number of Person(s): ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter "<<i+1<<".Seat Number: ";cin>>seatNo;
		cout<<"Enter Name of Person "<<i+1<<": ";cin>>name;
		r=(seatNo-1)/7;
		c=(seatNo-1)%7;
		if(!row[r].occupy(c,name)){
			i--;
			cout<<"Seat No. "<<seatNo<<" is Already Occupied\n";
			cout<<"Kindly Choose Another Seat\n";
		}
		else
			cout<<"Seat No. "<<seatNo<<" Confirmed\n";
	}
	display(row);
}
void List::cancel(List row[10]){
	int n,seatNo,r,c;
	string name;
	cout<<"Number of Tickets: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter "<<i+1<<".Seat Number: ";cin>>seatNo;
		cout<<"Enter Name of Person "<<i+1<<": ";cin>>name;
		r=(seatNo-1)/7;
		c=(seatNo-1)%7;
		if(row[r].unoccupy(c,name)==0){
			cout<<"Seat No. "<<seatNo<<" is Already Un-Occupied\n";
			cout<<"Check your Seat No. and Try again!\n";
			return;
		}
		else if(row[r].unoccupy(c,name)==-1){
			cout<<"\nEntered Name Didn't Match as per Ticket";
			cout<<"\nTry again!";
			return;
		}
	}
	display(row);
	cout<<"\nCancellation Successful! Verify Theatre Status";
	return;
}
int main() {
	List row[10],theatre;
	int ch=1,no,r,c,n;
	theatre.create(row);
	theatre.display(row);
	theatre.menu();
	do{
		cout<<endl<<"_______________________________________________";
		cout<<endl<<"Enter Your Choice [Press 0 to exit]: ";cin>>ch;
		switch(ch){
			case 1: theatre.display(row);
					break;
			case 2: theatre.book(row);
					cout<<"\nThankYou For Booking...";
					break;
			case 3: theatre.cancel(row);
					break;
			default: cout<<"Invalid Choice";
		}
	}while(ch!=0);
	return 0;
}

 
 
 
