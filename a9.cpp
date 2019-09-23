#include<bits/stdc++.h>
using namespace std;
class Node{
	string code;
	int priority;
	Node *link;
public:
	Node();
	Node(string,int);
	friend class Queue;
};
Node::Node(){
	code="0000";
	priority=0;
	link=NULL;
}
Node::Node(string _code,int _priority=0){
	code=_code;
	priority=_priority;
	link=NULL;
}
class Queue{
	Node *front;
	Node *rear;
public:
	Queue();
	void simpleEnqueue(string);
	void priorityEnqueue(string,int);
	void dequeue();
	void display();
	void menu();
};
Queue::Queue(){
	front=rear=NULL;
}
void Queue::simpleEnqueue(string _code){
	Node *temp;
	temp=new Node(_code);
	if(front==NULL){
		front=rear=temp;
		return;
	}
	rear->link=temp;
	rear=temp;
}
void Queue::priorityEnqueue(string _code,int _priority){
	Node *temp,*ptr,*p;
	ptr=NULL;
	temp=new Node(_code,_priority);
	if(front==NULL){
		front=rear=temp;
		return;
	}
	for(p=front;p->priority>_priority;p=p->link){
		ptr=p;
		if(p==rear){
			rear->link=temp;
			rear=temp;
			return;
		}
	}
	if(ptr!=NULL){
		ptr->link=temp;
		if(p!=NULL)
			temp->link=p;
		return;
	}
	temp->link=p;
	front=temp;

}
void Queue::display(){
	Node *ptr;
	if(front==NULL){
		cout<<"\nTask Queue is Empty!";
		return;
	}
	cout<<"\n#FRONT <-- ";
	for(ptr=front;ptr!=NULL;ptr=ptr->link)
		cout<<ptr->code<<" <-- ";
	cout<<"#REAR";
}
void Queue::dequeue(){
	Node *temp;
	if(front==NULL){
		cout<<"\nTask Queue is Already Empty!";
		return;
	}
	temp=front;
	front=front->link;
	delete temp;
}
void Queue::menu(){
	cout<<"\n------------------TASK SCHEDULING-------------------";
	cout<<"\nPress 1: Add Task in Simple Queue";
	cout<<"\nPress 2: Perform and Remove Task in Simple Queue";
	cout<<"\nPress 3: Enlist Simple Queue";
	cout<<"\n\nPress 4: Add Task in Priority Queue";
	cout<<"\nPress 5: Perform and Remove Task in Priority Queue";
	cout<<"\nPress 6: Enlist Priority Queue";
	cout<<"\n\nPress 9: Display Options";
}
int main(){
	Queue simpleQueue,priorityQueue;
	string code;
	int choice,priority;
	simpleQueue.menu();
	do{
		cout<<endl<<"____________________________________________________";
		cout<<endl<<"Enter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Task Code: ";cin>>code;
					simpleQueue.simpleEnqueue(code);
					break;
			case 2: simpleQueue.dequeue();
					break;
			case 3: simpleQueue.display();
					break;
			case 4: cout<<"\nEnter Task Code: ";cin>>code;
					cout<<"\nEnter Task Priority: ";cin>>priority;
					priorityQueue.priorityEnqueue(code,priority);
					break;
			case 5: priorityQueue.dequeue();
					break;
			case 6: priorityQueue.display();
					break;
			case 9: simpleQueue.menu();
					break;
			case 0: cout<<"\n----------------------END---------------------------";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);


	return 0;
}

