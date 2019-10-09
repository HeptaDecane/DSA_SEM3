//============================================================================
// Name        : a11.cpp
// Author      : Near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define MAX 50
class Database{
	int array[MAX];
	int n;
public:
	Database();
	void setData();
	void display();
	int linearSearch(int);
	int sentinelSearch(int);
	int binarySearch(int);
	int fibonacciSearch(int);
	void menu();
};
Database::Database(){
	for(int i=0;i<MAX;i++)
		array[i]=0;
	n=0;
}
void Database::setData(){
	cout<<"\nEnter No. of Students Attended Training Program: ";
	cin>>n;
	for(int i=0;i<n;i++){
label:
		cout<<"Enter Roll No. : ";
		cin>>array[i];
		if(array[i]<=0){
			cout<<"\nError: Invalid Roll No.!\nTry Again!\n";
			goto label;
		}
		else
			for(int j=0;j<i;j++){
				if(array[j]==array[i]){
					cout<<"\nError: Roll No. "<<array[i]<<" Repeated!\nTry Again!\n";
					goto label;
				}
			}
	}
}
void Database::display(){
	cout<<"\nStudents Attended Training Program:";
	for(int i=0;i<n;i++)
		cout<<"\n\tRollNo. : "<<array[i];
}
int Database::fibonacciSearch(int key){
	int fib2=0;
	int fib1=1;
	int fib0=fib1+fib2;
	while(fib0<n){
		fib2=fib1;
		fib1=fib0;
		fib0=fib1+fib2;
	}
	int offset=-1;
	while(fib0>1){
		int i=min(offset+fib2,n-1);
		if(key>array[i]){
			fib0=fib1;
			fib1=fib2;
			fib2=fib0-fib1;
			offset=i;
		}
		else if(key<array[i]){
			fib0=fib2;
			fib1=fib1-fib2;
			fib2=fib0-fib1;
		}
		else
			return i;
	}
	if(fib1 && array[offset+1]==key)
		return offset+1;
	return -1;
}
int Database::binarySearch(int key){
	int start=0;
	int end=n-1;
	int mid=(start+end)/2;
	while(start<=end){
		if(key>array[mid])
			start=mid+1;
		else if(key<array[mid])
			end=mid-1;
		else
			return mid;
		mid=(start+end)/2;
	}
	return -1;
}
int Database::sentinelSearch(int key){
	array[n]=key;
	int i=0;
	while(true){
		if(array[i]==key)
			break;
		i++;
	}
	if(i==n)
		return -1;
	else
		return i;
}
int Database::linearSearch(int key){
	for(int i=0;i<n;i++){
		if(array[i]==key)
			return i;
	}
	return -1;
}
void Database::menu(){
	cout<<"\n-----------------TRAINING PROGRAM-------------------";
	cout<<"\nPress 1: Input Training Program Attendance";
	cout<<"\nPress 2: Search by Linear Search";
	cout<<"\nPress 3: Search by Sentinel Search";
	cout<<"\nPress 4: Search by Binary Search";
	cout<<"\nPress 5: Search by Fibonacci Search";
	cout<<"\nPress 6: Display Attendance";
	cout<<"\nPress 9: Display Operations";
}
int main(){
	Database container;
	int choice,key,index=-1;
	container.menu();
	do{
		cout<<endl<<"____________________________________________________";
		cout<<endl<<"Enter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Element: ";
					index=container.setData();
					if(index<0)
						cout<<"\n"<<key<<" is not found in list";
					else
						cout<<"\n"<<key<<" found at index: "<<index;
					break;
			case 2: cout<<"\nEnter Element to Search : ";cin>>key;
					index=container.linearSearch(key);
					if(index<0)
						cout<<"\n"<<key<<" is not found in list";
					else
						cout<<"\n"<<key<<" found at index: "<<index;
					break;
			case 3: cout<<"\nEnter Element to Search : ";cin>>key;
					index=container.sentinelSearch(key);
					if(index<0)
						cout<<"\n"<<key<<" is not found in list";
					else
						cout<<"\n"<<key<<" found at index: "<<index;
					break;
			case 4: cout<<"\nEnter Element to Search : ";cin>>key;
					index=container.binarySearch(key);
					if(index<0)
						cout<<"\n"<<key<<" is not found in list";
					else
						cout<<"\n"<<key<<" found at index: "<<index;
					break;
			case 5: cout<<"\nEnter Element to Search : ";cin>>key;
					index=container.fibonacciSearch(key);
					if(index<0)
						cout<<"\n"<<key<<" is not found in list";
					else
						cout<<"\n"<<key<<" found at index: "<<index;
					break;
			case 6: container.display();
					break;
			case 9: container.menu();
					break;
			case 0: cout<<"\n----------------------END---------------------------\n";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);
	return 0;
}








