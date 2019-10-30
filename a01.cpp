//============================================================================
//						Assignment 2
// Roll No.    : 21164
// Name        : Sooraj VS
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
class Student{
	int rollNo;
	float marks;
public:
	Student();
	void read();
	void display();
	friend class Database;
};
Student::Student(){
	rollNo=0;
	marks=0.0;
}
void Student::read(){
validation1:
	cout<<"\nRoll No : ";cin>>rollNo;
	if(rollNo<1){
		cout<<"\nInvalid Roll No, Try Again!";
		goto validation1;
	}
validation2:
	cout<<"\nMarks   : ";cin>>marks;
	if(marks<-1||marks>100){
		cout<<"\nInvalid Marks, Try Again!";
		goto validation2;
	}
}
void Student::display(){
	if(marks==-1){
		cout<<"\n "<<rollNo<<"\t\tA";
		return;
	}
	cout<<"\n "<<rollNo<<"\t\t"<<marks;
}

class Database{
	Student *s;
	int t,p;
public:
	Database();
	Database(int);
	void allocate(int);
	void read();
	void display();
	int absent();
	Student maxMarks();
	Student minMarks();
	void searchStudent(Student);
	float average();
	int mode();
	void menu();
	void arrange();
};
Database::Database(){
	s=NULL;
	t=0;
	p=0;
}
Database::Database(int n){
	this->t=n;
	s=new Student[this->t];
	p=0;
}
void Database::allocate(int n){
	this->t=n;
	s=new Student[this->t];
	p=0;
}
void Database::arrange(){
	Student temp;
	for(int i=0;i<t;i++){
		for(int j=i+1;j<t;j++){
			if(s[i].rollNo>s[j].rollNo){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}
void Database::read(){
	for(int i=0;i<t;i++){
validation3:
		cout<<"\nStudent "<<i+1;
		s[i].read();
		for(int j=0;j<i;j++){
			if(s[i].rollNo==s[j].rollNo){
				cout<<"\nStudent Roll No. Repeated, Try Again!";
				goto validation3;
			}
		}
	}
	for(int i=0;i<t;i++){
		if(s[i].marks!=-1)
			p++;
	}
}
float Database::average(){
	float avg=0.0;
	for(int i=0;i<t;i++){
		if(s[i].marks!=-1)
			avg+=s[i].marks;
	}
	if(p)
		avg=avg/p;
	return avg;
}
int Database::mode(){
	Student temp;
	int count=0,frequency=0;
	for(int i=0;i<t;i++){
		for(int j=i+1;j<t;j++){
			if(s[i].marks>s[j].marks){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	for(int i=0;i<t;i++){
		count=0;
		if(s[i].marks!=-1){
			for(int j=0;j<t;j++){
				if(s[i].marks==s[j].marks)
					count++;
			}
		}
		if(count>=frequency){
			frequency=count;
			temp=s[i];
		}
	}
	if(frequency==1)
		return 0;
	cout<<"\nMost Scored Marks = "<<temp.marks;
	return frequency;	
}
void Database::display(){
	cout<<"\nMARKS DATABASE: ";
	cout<<"\nRoll No.\tMarks";
	for(int i=0;i<t;i++){
		s[i].display();
	}
}
Student Database::maxMarks(){
	Student max;
	for(int i=0;i<t;i++){
		if(s[i].marks>max.marks)
			max=s[i];
	}
	return max;
}
Student Database::minMarks(){
	Student min;
	min.marks=100;
	for(int i=0;i<t;i++){
		if(s[i].marks!=-1&&s[i].marks<min.marks)
			min=s[i];
	}
	return min;
}
void Database::searchStudent(Student a){
	for(int i=0;i<t;i++){
		if(s[i].marks==a.marks)
			s[i].display();
	}
	return;
}
int Database::absent(){
	for(int i=0;i<t;i++)
		if(s[i].marks==-1)
			s[i].display();
	return t-p;
}
void Database::menu(){
	cout<<"\n----------------------DATABASE MENU----------------------";
	cout<<"\n| Press 1: Re-Enter Test Database                       |";
	cout<<"\n| Press 2: Display Test Database                        |";
	cout<<"\n| Press 3: Most Scored Marks                            |";
	cout<<"\n| Press 4: Average Score of the Test                    |";
	cout<<"\n| Press 5: Max Score of the Test                        |";
	cout<<"\n| Press 6: Max Score of the Test                        |";
	cout<<"\n| Press 7: Absent Students List                         |";
	cout<<"\n---------------------------------------------------------";
} 
int main(){
	int choice,n,count=0;
	Student s;
	cout<<"\n----------------------DATABASE ENTRY---------------------";
	cout<<"\nEnter No. of Students: ";
	cin>>n;
	Database dsa(n);
	dsa.read();
	dsa.arrange();
	cout<<"\nData Entry Successful!";
	dsa.menu();
	do{
		cout<<"\n---------------------------------------------------------";
		cout<<"\nEnter Choice [0-Exit|9-Menu]: ";
		cin>>choice;
		switch(choice){
			case 0:	cout<<"\n---------------------------END---------------------------";
					break;
			case 1:	cout<<"\n----------------------DATABASE ENTRY---------------------";
					cout<<"\nEnter No. of Students: ";
					cin>>n;
					dsa.allocate(n);
					dsa.read();
					dsa.arrange();
					cout<<"\nData Entry Successful!";
					break;
			case 2:	dsa.display();
					break;
			case 3: count=dsa.mode();
					if(count)
						cout<<", Scored by "<<count<<" Students";
					else
						cout<<"\nNo Scores Repeated!";
					dsa.arrange();
					break;
			case 4:	cout<<"\nAverage Test Score = "<<dsa.average();
					break;
			case 5:	s=dsa.maxMarks();
					cout<<"\nHighest Score:";
					cout<<"\nRoll No.\tMarks";
					dsa.searchStudent(s);
					break;
			case 6:	s=dsa.minMarks(); 
					cout<<"\nLowest Score:";
					cout<<"\nRoll No.\tMarks";
					dsa.searchStudent(s);
					break;
			case 7: cout<<"\nAbsent Students:";
					cout<<"\nRoll No.  --";
					count=dsa.absent();
					cout<<"\nAbsent Count = "<<count;
					break;
			case 9: dsa.menu();
					break;
			default:cout<<"\nInvalid Choice, Try Again!";
		}
		
	}while(choice);
	return 0;
}
