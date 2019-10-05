//============================================================================
// Name        : a10.cpp
// Author      : Near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class Deque{
	int array[MAX];
	int front;
	int rear;
public:
	Deque();
	void menu();
	void enqueueFront(int);
	void enqueueRear(int);
	void dequeueFront();
	void dequeueRear();
	void display();
	void display0();
	bool isEmpty();
	bool isFull();
	int peekFront();
	int peekRear();
};

Deque::Deque(){
	front=-1;
	rear=-1;
	for(int i=0;i<10;i++)
		array[i]=0;
}

bool Deque::isEmpty(){
	return(front==-1);
}

bool Deque::isFull(){
	return((front==0&&rear==MAX-1)||front==rear+1);
}

void Deque::enqueueFront(int key){
	if(isFull()){
		cout<<"\nError: Deque Full!";
		return;
	}
	if(front==-1)
		front=rear=0;
	else if(front==0)
		front=MAX-1;
	else 
		front=front-1;
	array[front]=key;
	cout<<"\n"<<key<<" Inserted at Front!";
}

void Deque::enqueueRear(int key){
	if(isFull()){
		cout<<"\nError: Deque Full!";
		return;
	}
	if(front==-1)
		front=rear=0;
	else if(rear==MAX-1)
		rear=0;
	else
		rear=rear+1;
	array[rear]=key;
	cout<<"\n"<<key<<" Inserted at Rear!";
}

void Deque::dequeueFront(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	array[front]=0;
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
	cout<<"\nDeleted Front Element!";
}

void Deque::dequeueRear(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	array[rear]=0;
	if(front==rear)
		front=rear=-1;
	else if(rear==0)
		rear=MAX-1;
	else
		rear=rear-1;
	cout<<"\nDeleted Rear Element!";	
}
int Deque::peekFront(){
	if(!isEmpty())
		return(array[front]);
}

int Deque::peekRear(){
	if(!isEmpty())
		return(array[rear]);
}

void Deque::display(){
	int i=front;
	cout<<"\nDeque: ";
		while(true){
			cout<<array[i]<<" ";
			if(i==rear)
				break;
			else if(i==MAX-1)
				i=0;
			else
				i++;
		}
}

void Deque::display0(){
	cout<<"\n";
	for(int i=0;i<MAX;i++)
		cout<<array[i]<<" ";
	cout<<"\nfront = "<<front;
	cout<<"\nrear = "<<rear;
}

void Deque::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Push Element at Front";
	cout<<"\nPress 2: Push Element at Rear";
	cout<<"\nPress 3: Pop Element at Front";
	cout<<"\nPress 4: Pop Element at Rear";
	cout<<"\nPress 5: Peek Front Element";
	cout<<"\nPress 6: Peek Rear Element";
	cout<<"\nPress 7: Display Deque";	
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
					container.enqueueFront(key);
					break;
			case 2: cout<<"\nEnter Element: ";cin>>key;
					container.enqueueRear(key);
					break;
			case 3: container.dequeueFront();
					break;
			case 4: container.dequeueRear();
					break;
			case 5: cout<<"\nFront Element = "<<container.peekFront();
					break;
			case 6: cout<<"\nRear Element = "<<container.peekRear();
					break;
			case 7: container.display();
					break;
			case 8: container.display0();
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




