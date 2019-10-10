#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Node{
	char data;
	Node *link;
public:
	Node(char);
	friend class List;
	friend class Hash;
};
Node::Node(char x){
	data=x;
	link=NULL;
}


class List{
	Node *start;
public:
	List(){
		start=NULL;
	}
	void pushBack(char);
	void sortList();
	bool deleteByValue(char);
	void display();
	int count();
	friend class Hash;
};
void List::pushBack(char _data){
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
bool List::deleteByValue(char _data){
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
	void insert(char);
	void display();
	void sortHash();
	void free();
	bool erase(char);
	string hashGenerator(string);
	string returnHash();
	int hashFunction(int);
	string hashChar(char);
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
void Hash::free(){
	for(int i=0;i<rows;i++)
		table[i].start=NULL;
}
string Hash::hashChar(char c){
	string str;
	char code[4];
	int ascii=(int)c;
	if(c==' ')
		return "9x";
	else if(c>='A'&&c<='Z'){
		code[0]=((ascii)%26)+65;
		code[1]=((ascii-17)%26)+65;
		code[2]=((ascii+13)%26)+65;
	}
	else if(c>='a'&&c<='z'){
		code[0]=((ascii)%26)+97;
		code[1]=((ascii-17)%26)+97;
		code[2]=((ascii+13)%26)+97;
	}
	else{
		stringstream buffer;
		buffer<<ascii;
		buffer>>str;
		return str;
	}
	code[3]='\0';
	str=code;
	return str;
}
void Hash::insert(char key){
	int index=hashFunction(key);
	table[index].pushBack(key);
}
bool Hash::erase(char key){
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
string Hash::hashGenerator(string str){
	for(int i=0;i<str.length();i++)
		insert(str[i]);
	return returnHash();	
}
string Hash::returnHash(){
	string str="#";
	int key;
	string code;
	for(int i=0;i<rows;i++){
		if(table[i].start!=NULL){
			stringstream buffer0;
			key=(i+1)^10;
			buffer0<<key;
			string substr0;
			buffer0>>substr0;
			str=str+substr0;
			Node *t=table[i].start;
			for(int j=0;t!=NULL;t=t->link){
				stringstream buffer1;
				key=(j+1)^7;
				buffer1<<key;
				string substr1;
				buffer1>>substr1;
				str=str+substr1;
				code=hashChar(t->data);
				str=str+code;
				j++;
			}
		}
	}
	return str;
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
	Hash container(13);
	string str="NearLawiet";
	string s1,str1,s2;
	s1=container.hashGenerator(str);
	container.free();
	cout<<"Enter String: ";cin>>str1;
	s2=container.hashGenerator(str1);
	if(s1==s2)
		cout<<"\nAccess Granted";
	else
		cout<<"\nAccess Denied";
	
	

	
	return 0;
}


