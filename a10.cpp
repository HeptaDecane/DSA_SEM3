//============================================================================
// Name        : a10.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class Deque{
	int arr[MAX];
	int front;
	int rear;
	int size;
public:
	Deque();
	void menu();
	void pushFront(int);
	void pushBack(int);
	void popFront();
	void popBack();
	void display();
	void display0();
	bool isEmpty();
	bool isFull();
	int peekFront();
	int peekBack();
};

Deque::Deque(){
	front=0;
	rear=-1;
	size=0;
	for(int i=0;i<MAX;i++)
		arr[i]=0;
}

bool Deque::isEmpty(){
	return(size<=0);
}

bool Deque::isFull(){
	return (size==MAX);
}

void Deque::pushFront(int key){
	if(isFull()){
		cout<<"\nError: Deque Full!";
		return;
	}
	size++;
	arr[front]=key;
	front=(front+1)%MAX;
	cout<<key<<" Added at Front";
}

void Deque::pushBack(int key){
	if(isFull()){
		cout<<"\nError: Deque Full!";
		return;
	}
	size++;
	arr[rear+MAX]=key;
	rear=(rear-1)%MAX;
	cout<<key<<" Added at Rear";
}

void Deque::popFront(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	size--;
	cout<<"\nFront Popped!";
	front=(front-1)%MAX;
}

void Deque::popBack(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	size--;
	cout<<"\nRear Popped!";
	rear=(rear+1)%MAX;
}

int Deque::peekFront(){
	int index=(front-1)%MAX;
	return(arr[index]);
}

int Deque::peekBack(){
	int index=(rear+1)%MAX+MAX;
	return(arr[index]);
}

void Deque::display(){
	cout<<"\nDeque: ";
	for(int i=front-1;i>rear;i--){
		if(i>=0)
			cout<<arr[i%MAX]<<" ";
		else
			cout<<arr[i%MAX+MAX]<<" ";
	}
	cout<<"\nNo. of Elements in Deque = "<<size;
	return;
}

void Deque::display0(){
	cout<<"\n";
	for(int i=0;i<MAX;i++)
		cout<<arr[i]<<" ";
	cout<<"\nfront = "<<front;
	cout<<"\nrear = "<<rear;
}

void Deque::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Push Element at Front";
	cout<<"\nPress 2: Push Element at Back";
	cout<<"\nPress 3: Pop Element at Front";
	cout<<"\nPress 4: Pop Element at Back";
	cout<<"\nPress 5: Display Deque";
//	cout<<"\nPress 8: Developer Display;";
	cout<<"\nPress 9: Display Operations";
}
int main(){
	Deque container;
	int choice,key;
	container.menu();
	do{
		cout<<endl<<"____________________________________________________";
		cout<<endl<<"Enter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Element: ";cin>>key;
					container.pushFront(key);
					break;
			case 2: cout<<"\nEnter Element: ";cin>>key;
					container.pushBack(key);
					break;
			case 3: container.popFront();
					break;
			case 4: container.popBack();
					break;
			case 5: container.display();
					break;
//			case 8: container.display0();
//					break;
			case 9: container.menu();
					break;
			case 0: cout<<"\n----------------------END---------------------------\n";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);
	return 0;
}




