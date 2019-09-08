#include <iostream>
#include<string>
using namespace std;
class Node
{
	int prn;
	string name;
	Node *next;
public:
	Node(int x,string nm)
{
		prn=x;
		next=NULL;
		name=nm;
}

friend class List;
};
class List
{
	Node *start;
public:
	List(){
		start=NULL;
	}
	void create();
	void display();
	void insertAtBeginning();
	void insertAtEnd();
	void insertAfter();
	void deleteAtFirst();
	void deleteByValue();
	void deleteAtEnd();
	int computeTotal();
	void sortList();
	void concatList(List &q1);
	void displayRev(Node *t);
	void menu();
	bool reverseDisplay() //function is only for passing start as argument to recursive function
         {
        	 if(start==NULL)
        		return false;
        	 Node *temp=start;
        	 displayRev(temp);
        	 //cout<<"(President)";
        	 return true;
         }
};
void List::menu(){
		cout<<"\n1. create\n2.Insert President\n3.Insert secretary\n4.insert after position(member)\n5.Display List"
		<<"\n6.Delete President\n7.Delete Secretary\n8.Delete Member\n9.Find total No. of members\n10.Sort List\n11. Reselect List "
		<<"\n12.Combine lists\n13.Reverse Display\n0. Exit";
}
void List::displayRev(Node *t)
{
	if(t==NULL)
		return;
	else
	{
		displayRev(t->next);
		cout<<"\nPRN NO:"<<t->prn<<" Name: "<<t->name;
	}
}
void List::create()
{
	int no;
	string nam;
	if(start==NULL)
	{
		cout<<"Enter PRN number: ";
		cin>>no;
		cout<<"Enter name: ";
		cin>>nam;
		cout<<nam;
		start=new Node(no,nam);
		cout<<"\n====== List Created =====";
		
	}
	else
	{
		cout<<"\nList is already created.";
	}
}
void List::display()
{
	Node *t;
	t=start;
	if(start==NULL)
		cout<<"\nList is Empty";
	else
	{ cout<<"\n====== List: ======\n";
		while(t!=NULL){
			cout<<t->prn<<"  "<<t->name<<" \n";
					t=t->next;
		}
		//cout<<t->prn<<"  "<<t->name<<" \n";
	}
}
void List::insertAtBeginning()
{
	int no;
	string nam;
 Node *temp;
 if(start==NULL)
 {
	 create();
 }
 else
 {
	 cout<<"\nEnter PRN number: ";
	 cin>>no;
	 cout<<"Enter name: ";
	 cin>>nam;
	 //cout<<nam;
	 temp=new Node(no,nam);
	 temp->next=start;
	 start=temp;;
	 cout<<"Inserted  "<<temp->name<<" at the beginning.";
 }
}
void List::insertAtEnd()
{
	int no;
	string nam;
	Node *t;
	if(start==NULL)
		create();
	else
	{
	 cout<<"\nEnter PRN number: ";
	 cin>>no;
	 cout<<"Enter name: ";
	 cin>>nam;
	 t=start;
	 while(t->next!=NULL)
	 	t=t->next;
	 	
	 	Node*p=new Node(no,nam);
	 	t->next=p;
	}
}
void List::insertAfter()
{
	int prev_no;
	cout<<"\nENter PRN No. after do you want insert:";
	cin>>prev_no;
	Node *t;
	t=start;
	string nam;
	int flag=0,no;
	while(t!=NULL)
	{
		if(t->prn==prev_no)
		{
			flag=1;break;
		}
		t=t->next;
	}
	if(flag==1)
	{
		Node *p;
		cout<<"\nEnter PRN number: ";
	 cin>>no;
	 cout<<"Enter name: ";
	 cin>>nam;
	 p=new Node(no,nam);
	 p->next=t->next;
	 t->next=p;
	}
	else
	{
		cout<<"\n"<<prev_no<<" is not in List.";
	}
	
}

void List::deleteAtFirst()
{
	Node *t;
	if(start==NULL)
		cout<<"\nClub is Empty..";
	else
	{
	t=start;
	start=start->next;
	t->next=NULL; //Not necessary
	delete t;
	cout<<"\nPresident deleted..";
}
}

void List::deleteByValue()
{
	int no,flag=0;
	Node *t,*prev;
	if(start==NULL)
		cout<<"\nList/Club is empty;";
	else
	{
		cout<<"\nEnter PRN no. of member to be deleted: ";
		cin>>no;
		t=start->next; //t=start if we have to delete precident also.. start->next is first member
		while(t->next!=NULL)
		{
			if(t->prn==no){
				flag=1;
				break;
			}
			prev=t;
			t=t->next;
		}
		if(flag==1)
		{
			prev->next=t->next;
			t->next=NULL;
			delete t;
			cout<<"\nMember with prn no: "<<no<<" is deleted.";
		}
		else
			cout<<"\nMember not found in List./president or secretary cannot be deleted.";
	}
}
void List::deleteAtEnd()
{
	Node *t,*prev;
	t=start;
		if(start==NULL)
		cout<<"\nClub is Empty..";
	else
	{
	while(t->next!=NULL)
	{
		prev=t;
		t=t->next;
	}
	prev->next=NULL;
	delete t;
	cout<<"\nSecretary Deleted.";
}
}
int List::computeTotal()
{
Node *t;
int count=0;
t=start;
if(start==NULL)
{
	cout<<"\nList is empty.";
	return 0;
}
while(t!=NULL)
{
count++;
t=t->next;
}

return count;
}

void List::sortList()
{
	Node *i,*j,*last=NULL;
	int tprn;
	string tname;

if(start==NULL)
{
	cout<<"\nList is empty.";
	return ;
}
for(i=start;i->next!=NULL;i=i->next)
{
	for(j=start;j->next!=last;j=j->next)
	{
		if((j->prn)>(j->next->prn))
		{
			tprn=j->prn;
			tname=j->name;
			j->prn=j->next->prn;
			j->name=j->next->name;

			j->next->prn=tprn;
			j->next->name=tname;

		}
	}
}
cout<<"\n List is sorted.";
display();
}
void List::concatList(List &q1)
{
	Node *t,*p;
	t=q1.start;
	if(t==NULL)
	{
		cout<<"\nList 2 is empty";
		return;
	}
	p=start; //first List
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=t;
	q1.start=NULL; //second List is set to  null
	cout<<"\nAfter concatenationlist";
	display();
	
}
int main() {
	List *l;
	int choice,selectList;
	List l1,l2;
	l=&l1;
	X:cout<<"\nSelect List\n1.List 1\n2.List 2\nEnter choice: ";
	cin>>selectList;

	if(selectList==1)
	{
		l=&l1;
	}
	else if(selectList==2)
	{
		l=&l2;
	}
	else
	{
		cout<<"\nWrong List Number.";
		goto X;
	}
	l1.menu();
	do
	{
		cout<<"\nEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: l->create();
				break;
			case 2:	l->insertAtBeginning();
				break;
			case 3: l->insertAtEnd();
				break;
			case 4: l->insertAfter();
				break;
			case 5: l->display();
				break;
			case 6: l->deleteAtFirst();
				break;
			case 7: l->deleteAtEnd();
				break;
			case 8: l->deleteByValue();
				break;
			case 9:	cout<<"\nTotal members(including President & Secretary): "<<l->computeTotal();
				break;
			case 10: l->sortList();
			break;
			case 11:
				goto X;
				break;
				case 12:
					l1.concatList(l2);
					break;
				case 13:
					l->reverseDisplay();
					break;
			deafult:
				 cout<<"Wrong choice";
		}
	}while(choice!=0);
cout<<"\nEND...\n";
	
	return 0;
}
