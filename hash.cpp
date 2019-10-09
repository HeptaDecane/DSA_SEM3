#include<bits/stdc++.h>
using namespace std;
class Node{
	int data;
	Node *link;
public:
	Node(int);
	friend class List;
};
Node::Node(int x){
	data=x;
	link=NULL;
}


class List{
	Node *start;
public:
	List(){
		start=NULL;
	}
	void pushBack(int);
	void sortList();
	bool deleteByValue(int);
	void display();
	int count();
	friend class Hash;
};
void List::pushBack(int _data){
	Node *temp,*t;
	temp=new Node(_data);
	if(start==NULL){
		start=temp;
		return;
	}
	t=start;
	while(t->link!=NULL)
		t=t->link;
	t->link=temp;
}
bool List::deleteByValue(int _data){
	Node *t,*prev;
	if(start==NULL){
		cout<<"\nRow Empty";
		return false;
	}
	if(start->data==_data){
		t=start;
		start=start->link;
		t->link=NULL;
		delete t;
		return true;
	}
	t=start;
	while(t->link!=NULL){
		if(t->data==_data){
			prev->link=t->link;
			return true;
		}
		prev=t;
		t=t->link;
	}
	if(t->data==_data){
		prev->link=NULL;
		delete t;
		return true;
	}
	return false;
}
void List::sortList(){
	Node *i,*j;
	int temp;
	if(start==NULL)
		return ;
	for(i=start;i!=NULL;i=i->link){
		for(j=i->link;j!=NULL;j=j->link){
			if((i->data)>(j->data)){
				temp=j->data;
				j->data=i->data;
				i->data=temp;
			}
		}
	}
}
int List::count(){
	Node *t;
	int _count=0;
	for(t=start;t!=NULL;t=t->link)
		_count++;
	return _count;
}
void List::display(){
	Node* t;
	cout<<" ----> ";
	for(t=start;t!=NULL;t=t->link)
		cout<<t->data<<" ----> ";
	cout<<"#";
}

class Hash{
	int rows;
	List *table;
public:
	Hash();
	Hash(int);
	void insert(int);
	void display();
	void sortHash();
	bool erase(int);
	int hashFunction(int);
	int count();
};
Hash::Hash(){
	rows=0;
	table=NULL;
}
Hash::Hash(int r){
	rows=r;
	table=new List[rows];
}
int Hash::hashFunction(int key){
	return (key%rows);
}
void Hash::insert(int key){
	int index=hashFunction(key);
	table[index].pushBack(key);
}
bool Hash::erase(int key){
	int index=hashFunction(key);
	return table[index].deleteByValue(key);
}
void Hash::display(){
	for(int i=0;i<rows;i++){
		cout<<i<<":";
		table[i].display();
		cout<<"\n";
	}
}
void Hash::sortHash(){
	for(int i=0;i<rows;i++)
		table[i].sortList();
}
int Hash::count(){
	int total=0;
	for(int i=0;i<rows;i++)
		total+=table[i].count();
	return total;
}
int main(){
	Hash container(17);
	for(int i=100;i>=1;i--)
		container.insert(i);
	container.display();
	container.sortHash();cout<<"\n";
	container.display();
	return 0;
}



