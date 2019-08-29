//============================================================================
// Name        : Assignment.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Student{
private:
	int prn;
	string name,division;
	Student*  next;
public:
	Student();
	Student(int,string,string);
	void setData(int,string,string);
	void display();
	friend class Club;
};
Student::Student(int _prn,string _name,string _division){
	prn=_prn;
	name=_name;
	division=_division;
	next=NULL;
}
void Student::display(){
	cout<<name<<" "<<prn<<" "<<division<<endl;
}
class Club{
private:
	Student* start;
public:
	Club();
	Club(int);
	void read(int);
	void display();
	void menu();
	void addPresident(int,string,string);
	void addSecretary(int,string,string);
	void addMember(int,string,string);
	void deletePresident();
	void deleteMember(int);
	void deleteSecretary();
	int searchMember(int);
};
Club::Club(){
	start=NULL;
}
void Club::read(int n){
	int prn;
	string name,division;
	cout<<"Details: ";
	cin>>prn>>name>>division;
	start=new Student(prn,name,division);
	Student* t=start;
	for(int i=1;i<n;i++){
		cin>>prn>>name>>division;
		Student* current=new Student(prn,name,division);
		t->next=current;
		t=current;
	}
}
void Club::display(){
	Student *t=start;
	while(t!=NULL){
		t->display();
		t=t->next;
	}
}
void Club::addPresident(int prn,string name,string division){
	Student* temp=new Student(prn,name,division);
	if(start==NULL){
		start=temp;
	}
	else{
		temp->next=start;
		start=temp;
	}
}
void Club::addSecretary(int prn,string name,string division){
	Student* t=start;
	Student* temp=new Student(prn,name,division);
	if(start==NULL){
		cout<<"No President Found";
	}
	else{
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
		temp->next=NULL;
	}
}
void Club::addMember(int prn,string name,string division){
	Student* current=new Student(prn,name,division);
	if(start==NULL||start->next==NULL){
		cout<<"No President Found";
	}
	else{
		current->next=start->next;
		start->next=current;
	}
}
void Club::deleteMember(int pos){
	Student *t=start;
	Student *temp=NULL;
	for(int i=0;i<pos;i++){
		t=t->next;
	}
	temp=t->next;
	t->next=(t->next)->next;
	temp->next=NULL;
	delete temp;
	cout<<"Member Deleted";
}
int Club::searchMember(int prn){
	Student *t=start->next;
	int i=0;
	if(start==NULL){
		cout<<"List empty";
		return -1;	
	}
	else{
		while(t->next!=NULL){
			if(t->prn==prn){
				return i;
			}
			t=t->next;
			i++;
		}
		cout<<"Member Not Found";
		return -1;
	}
}
void Club::deletePresident(){
	Student *temp=NULL;
	if(start==NULL){
		cout<<"No President Found";
	}
	else{
		temp=start;
		start=start->next;
		temp->next=NULL;
		delete temp;
		cout<<"President Deleted!";
	}
}
void Club::deleteSecretary(){
	Student *t=start->next;
	Student *temp=NULL;
	if(start==NULL){
		cout<<"No President Found";	
	}
	else{
		while((t->next)->next!=NULL){
			t=t->next;
		}
		temp=t->next;
		t->next=NULL;
		delete temp;
	}
}
void Club::menu(){
	cout<<"------------------POLYNOMIAL--------------------"<<endl;
	cout<<"\tPress 1 : Display List"<<endl;
	cout<<"\tPress 2 : Add President"<<endl;
	cout<<"\tPress 3 : Add Secretary"<<endl;
	cout<<"\tPress 4 : Add Member"<<endl;
	cout<<"\tPress 5 : Delete Member"<<endl;
	cout<<"\tPress 6 : Delete President"<<endl;
	cout<<"\tPress 7 : Delete Secretary"<<endl;
	cout<<"\tPress 0 to exit"<<endl;
}
int main(){
	int ch=1,n,prn,pos;
	string name,division;
	Club pinnacle;
	pinnacle.menu();
	cout<<endl<<"_______________________________________________";
	cout<<endl<<"Enter Choice from Menu [Press 0 to exit]: ";
	cin>>ch;
	while(ch!=0){
		switch(ch){
			case 1:
				pinnacle.display();
				break;
			case 2:
				cout<<"Enter Prn Number: ";cin>>prn;
				cout<<"Enter Name: ";cin>>name;
				cout<<"Enter Division: ";cin>>division;
				pinnacle.addPresident(prn,name,division);
				break;
			case 3:
				cout<<"Enter Prn Number: ";cin>>prn;
				cout<<"Enter Name: ";cin>>name;
				cout<<"Enter Division: ";cin>>division;
				pinnacle.addSecretary(prn,name,division);
				break;
			case 4:
				cout<<"Enter Prn Number: ";cin>>prn;
				cout<<"Enter Name: ";cin>>name;
				cout<<"Enter Division: ";cin>>division;
				pinnacle.addMember(prn,name,division);
				break;
			case 5:
				cout<<"Enter Prn of the Member: ";cin>>prn;
				pos=pinnacle.searchMember(prn);
				if(pos>0)
				{
					pinnacle.deleteMember(pos);
				}
				break;
			case 6:
				pinnacle.deletePresident();
				break;
			case 7:
				pinnacle.deleteSecretary();
				break;
			default:
				cout<<"Invalid choice "<<ch;
		}
		cout<<endl<<"_______________________________________________";
		cout<<endl<<"Enter Choice from Menu [Press 0 to exit]: ";
		cin>>ch;
	}
	return 0;
}


