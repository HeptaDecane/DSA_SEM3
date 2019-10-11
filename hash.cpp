#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<fstream>
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
	int search(char);
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
int List::search(char key){
	Node *t;
	int index=0;
	for(t=start;t!=NULL;t=t->link){
		if(t->data==key)
			return index;
		index++;
	}
	return -1;
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
	void demoMenu();
	void hashingMenu();
	bool erase(char);
	int search(char);
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
int Hash::search(char key){
	int index=hashFunction(key);
	return table[index].search(key);
}
void Hash::demoMenu(){
	cout<<"\n------------------DEMONSTRATION--------------------";
	cout<<"\n| Press 1: Insert Character into HashTable        |";
	cout<<"\n| Press 2: Display HashTable Arrangement          |";
	cout<<"\n| Press 3: Count Entries in HashTable             |";
	cout<<"\n| Press 4: Sort HashTable                         |";
	cout<<"\n| Press 5: Search element in HashTable            |";
	cout<<"\n| Press 6: Delete element from HashTable          |";
	cout<<"\n| Press 9: Display Options                        |";
	cout<<"\n| Press 0: Exit From Demonstration                |";
	cout<<"\n---------------------------------------------------";
}
void Hash::hashingMenu(){
	cout<<"\n----------------PASSWORD HASHING-------------------";
	cout<<"\n| Press 1: Create Password Hashed File            |";
	cout<<"\n| Press 2: Change Existing PassWord               |";
	cout<<"\n| Press 3: Show Hashed Password                   |";
	cout<<"\n| Press 9: Display Options                        |";
	cout<<"\n| Press 0: Exit From Demonstration                |";
	cout<<"\n---------------------------------------------------";
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

class Main{
public:
	int demo();
	int hashing();
};
int Main::demo(){
	int n;
	cout<<"\n@DEMONSTRATION";
	cout<<"\n\nNote:";
	cout<<"\n     Hash function used: key % No. of Rows";
	cout<<"\n     Hence, Any Prime Number is Recommended as No. of Rows\n";
	cout<<"\nEnter No. of Rows to construct HashTable: ";
	cin>>n;
	Hash container(n);
	cout<<"\nHashTable With "<<n<<" Rows Created!";
	int choice,index;
	char key;
	container.demoMenu();
	do{
		cout<<"\n\n@DEMONSTRATION_____________________________________";
		cout<<"\nEnter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Character: ";cin>>key;
					container.insert(key);
					cout<<key<<" Inserted!";
					break;
			case 2: container.display();
					break;
			case 3: cout<<"\nNo. of Entries = "<<container.count();
					break;
			case 4: container.sortHash();
					cout<<"\nHashTable Sorted in Alphabetic order!";
					break;
			case 5: cout<<"\nEnter Target Element to Search: ";cin>>key;
					index=container.search(key);
					if(index<0)
						cout<<key<<" Not Found in HashTable!";
					else
						cout<<key<<" Found at:\n  Row: "<<container.hashFunction(key)<<"\n  Pos: "<<index;
					break;
			case 6: cout<<"\nEnter Target Element to Delete: ";cin>>key;
					if(container.erase(key))
						cout<<key<<" Erased from HashTable!";
					else
						cout<<key<<" Not Found in HashTable!";
					break;
			case 9: container.demoMenu();
					break;
			case 0: cout<<"\n---------------------------------------------------\n";
					break;
			default: cout<<"\nInvalid Choice! Try Again!";
		}
	}while(choice);
	container.free();
	cout<<"\n";
	return 0;
}
int Main::hashing(){
	string pass0,hash0,newPass,newHash;
	Hash container(13);
	int choice;
	fstream file;
	cout<<"\n@HASHING";
	container.hashingMenu();	
	do{
		cout<<"\n\n@HASHING__________________________________________";
		cout<<"\nEnter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: file.open("password_hash.txt",ios::in|ios::out|ios::ate);
					if(!file.tellp()){
						cout<<"\nEnter PassWord: ";cin>>pass0;
						hash0=container.hashGenerator(pass0);
						file<<hash0;
						cout<<"\nPassWord Set Successfully!";
					}
					else
						cout<<"\nPassWord Already Exists!";
					file.close();
					container.free();
					break;
			case 2: file.open("password_hash.txt",ios::in|ios::out|ios::ate);
					if(file.tellp()){
						string currentPass,currentHash,oldHash;
						file.close();
						file.open("password_hash.txt",ios::in);
						file>>oldHash;
						cout<<"\nEnter Current PassWord: ";cin>>currentPass;
						currentHash=container.hashGenerator(currentPass);
						file.close();
						container.free();
						if(currentHash==oldHash){
							cout<<"\nEnter New PassWord: ";cin>>newPass;
							newHash=container.hashGenerator(newPass);
							file.open("password_hash.txt",ios::out|ios::trunc);
							file<<newHash;
							file.close();
							cout<<"\nPassWord Changed Successfully!";
						}
						else
							cout<<"\nWrong PassWord! Try Again.";
					}
					else
						cout<<"\nPassWord Doesn't Exists.";
					file.close();
					container.free();
					break;
			case 3: file.open("password_hash.txt",ios::in|ios::out|ios::ate);
					if(file.tellp()){
						file.close();
						string currentHash;
						file.open("password_hash.txt",ios::in);
						file>>currentHash;
						cout<<"\nHashed PassWord: "<<currentHash;
						file.close();
					}
					else
						cout<<"\nPassWord Doesn't Exists.";
					file.close();
					break;
			case 9: container.hashingMenu();
					break;
			case 0: cout<<"\n---------------------------------------------------\n";
					break;
			default: cout<<"\nInvalid Choice! Try Again!";
		}
	}while(choice);
	container.free();
	cout<<"\n";
	return 0;
}
int main(){
	Main driver;
	fstream file;
	file.open("password_hash.txt",ios::out|ios::app);
	file.close();
	int choice;
	cout<<"\n@ MAIN MENU\n";
	cout<<"\n-------------------HASH TABLES---------------------";
	cout<<"\n|  Press 1: Demonstration of DataStructure        |";
	cout<<"\n|  Press 2: Simulate PassWord Hashing             |";
	cout<<"\n|  Press 0: Exit From Program                     |";
	cout<<"\n---------------------------------------------------";
	cout<<"\nEnter Choice: ";cin>>choice;
	while(choice){
		switch(choice){
			case 1:	driver.demo();
					cout<<"\n@ MAIN MENU\n";
					break;
			case 2: driver.hashing();
					cout<<"\n@ MAIN MENU\n";
					break;
			default: cout<<"\nInvalid Choice! Try Again!";
		}
		cout<<"\n-------------------HASH TABLES---------------------";
		cout<<"\n|  Press 1: Demonstration of DataStructure        |";
		cout<<"\n|  Press 2: Simulate PassWord Hashing             |";
		cout<<"\n|  Press 0: Exit From Program                     |";
		cout<<"\n---------------------------------------------------";
		cout<<"\nEnter Choice: ";cin>>choice;
	}
	cout<<"\n-----------------------END-------------------------\n";
	return 0;
}



