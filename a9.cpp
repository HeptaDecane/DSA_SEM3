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
int main(){
	Queue simpleQueue,priorityQueue;
	simpleQueue.simpleEnqueue("abc");
	simpleQueue.simpleEnqueue("def");
	simpleQueue.simpleEnqueue("ghi");
	simpleQueue.simpleEnqueue("jkl");
	simpleQueue.simpleEnqueue("mno");
	simpleQueue.simpleEnqueue("pqr");
	simpleQueue.simpleEnqueue("stu");
	simpleQueue.simpleEnqueue("vwx");
	simpleQueue.dequeue();
	simpleQueue.dequeue();
	simpleQueue.dequeue();
	simpleQueue.display();
	priorityQueue.priorityEnqueue("a",2);
	priorityQueue.priorityEnqueue("z",1);
	priorityQueue.priorityEnqueue("c",4);
	priorityQueue.priorityEnqueue("b",23);
	priorityQueue.priorityEnqueue("k",0);
//	priorityQueue.dequeue();
//	priorityQueue.dequeue();
//	priorityQueue.dequeue();
//	priorityQueue.dequeue();
//	priorityQueue.dequeue();
//	priorityQueue.dequeue();
	priorityQueue.display();
	
	return 0;
}



