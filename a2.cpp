//============================================================================
//						Assignment 2
// Roll No.    : 21164
// Name        : Sooraj VS
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

class str
{
	char ch[200];
	public:
	str(){ ch[0]='\0'; }
	void read();
	void display();
	int substr(str);
	int subStr(str);
	int replace(str,str);
	void copy(str);
	void menu();
	int len();
	void concat(str);
	void reverse();
	int compare(str);
	int frequency(char);
	int palindrome();
	str chardelete(char);
	str modify(int,int);
};
str str::modify(int start,int span)
{
	str s;
	int i,j=0;
	for(i=0;i<len();i++)
	{
		if(i==start)
			i=i+span;
		else
		{
			s.ch[j]=ch[i];
			j++;
		}
	}
	s.ch[j]='\0';
	return s;
}
str str::chardelete(char c)
{
	str s;
	int i,j=0;
	for(i=0;i<len();i++)
	{
		if(ch[i]!=c)
		{
			s.ch[j]=ch[i];
			j++;
		}
	}
	if(i==j)
	cout<<"\t---->Character: "<<c<<" Not Found"<<endl;
	s.ch[j]='\0';
	return s;
}
int str::palindrome()
{
	int i,f=1,l=len();
	for(i=0;i<len();i++)
	if(ch[i]!=ch[l-i-1])
	f=0;
	if(f)
	return 1;
	else
	return 0;
}
int str::frequency(char c)
{
	int i,count=0;
	for(i=0;i<len();i++)
	{
		if(ch[i]==c)
		count++;
	}
	return count;
}
int str::compare(str s1)
{
	int f=1,i,l,l1;
	l=len();
	l1=s1.len();
	for(i=0;i<l;i++)
	if(ch[i]!=s1.ch[i])
	f=0;
	if(l1==l&&f)
	return 1;
	else
	return 0;
}
void str::reverse()
{
	int i,l=len();
	char temp;
	for(i=0;i<l/2;i++)
	{
		temp=ch[i];
		ch[i]=ch[l-i-1];
		ch[l-i-1]=temp;
	}
	ch[l]='\0';
}
void str::menu()
{
	cout<<endl<<"------------------STRING FUNCTIONS--------------------"<<endl;
	cout<<"\tPress 1  : Enter String"<<endl;
	cout<<"\tPress 2  : Display"<<endl;
	cout<<"\tPress 3  : Find Length"<<endl;
	cout<<"\tPress 4  : Copy"<<endl;
	cout<<"\tPress 5  : concatenate"<<endl;
	cout<<"\tPress 6  : find substring"<<endl;
	cout<<"\tPress 7  : replace a substring"<<endl;
	cout<<"\tPress 8  : Reverse the string"<<endl;
	cout<<"\tPress 9  : compare with another string"<<endl;
	cout<<"\tPress 10 : check frequency of any Character"<<endl;
	cout<<"\tPress 11 : check Palindrome"<<endl;
	cout<<"\tPress 12 : delete a character"<<endl;
	cout<<"\tPress 13 : delete by index and span"<<endl;
	cout<<"\tPress 0  : exit"<<endl;
}
int str::len()
{
	int i;
	for(i=0;ch[i]!='\0';i++);
	return i;
}
void str::copy(str s1)
{
	int i;
	for(i=0;s1.ch[i]!=0;i++)
	{
		ch[i]=s1.ch[i];
	}
	ch[i]='\0';
}
void str::read()
{
	cin.getline(ch,200);
}
void str::display()
{
	cout<<"\t -----> "<<ch;
}
void str::concat(str s1)
{
	int i,j,l1,l;
	l=len();
	l1=s1.len();
	for(i=l,j=0;j<l1;j++,i++)
	{
		ch[i]=s1.ch[j];
	}
	ch[i]='\0';
}
int str::substr(str s1)
{
	int l1,f,c=0,index[50],t=0;
	int i,j,l;
	l=len();

	l1=s1.len();
	for(i=0;i<=l-l1;i++)
	{
		f=1;
		for(j=0;j<l1;j++)
		{
			if(ch[i+j]!=s1.ch[j])
			f=0;
		}
		if(f!=0)
		{
			c++;
			index[t]=i;
			t++;
		}
	}
	if(c>0)
	{
		cout<<endl<<"yes at index value: ";
		for(i=0;i<t;i++)
		{
			cout<<index[i]<<", ";
		}
		return index[0];
	}
	else
	{
		cout<<endl<<s1.ch<<" Not Found in "<<ch;
		return -1;
	}
}
int str::subStr(str s1)
{
	int l1,f,c=0,index[50],t=0;
	int i,j,l;
	l=len();

	l1=s1.len();
	for(i=0;i<=l-l1;i++)
	{
		f=1;
		for(j=0;j<l1;j++)
		{
			if(ch[i+j]!=s1.ch[j])
			f=0;
		}
		if(f!=0)
		{
			c++;
			index[t]=i;
			t++;
		}
	}
	if(c>0)
		return index[0];
	else
		return -1;
}
int str::replace(str s1,str s2)
{
	int l1,index=0,l2;
	int i,count=0,j;
	str app;
		l1=s1.len();
		l2=s2.len();
		index=subStr(s1);
	while(index!=-1)
	{
		//Separating the append part
		count++;
		app.ch[0]='\0';
		for(i=index+l1,j=0;i<len();i++,j++)
		{
			app.ch[j]=ch[i];
		}
		app.ch[j]='\0';
		//coping the replacement
		for(i=index,j=0;j<l2;i++,j++)
		{
			ch[i]=s2.ch[j];
		}
		ch[i]='\0';
		concat(app);
		index=subStr(s1);
	}
	if(count)
		return 1;
	else
		return 0;
}
int main()
{
	str s,s1,s2,app;
	int ch=1,i,j;
	char c,buffer[10];
	s.menu();
	cout<<endl<<"\t";
	while (ch!=0){

		switch(ch)
		{
			case 1:cout<<"Enter The String: ";
					s.read();
					break;
			case 2: s.display();
					break;
			case 3: cout<<"-----> Length Of the string is: "<<s.len();
					break;
			case 4: cout<<"Enter String to be copied: ";
					s1.read();
					s.copy(s1);
					s.display();
					break;
			case 5: cout<<"Enter The append String: ";
					app.read();
					s.concat(app);
					s.display();
					break;
			case 6: cout<<"Enter the substring:";
					s1.read();
					s.substr(s1);
					break;
			case 7: cout<<"Enter the string to be replaced: ";
					s1.read();
					cout<<"Enter the Replacement: ";
					s2.read();
					if(s.replace(s1,s2))
					s.display();
					else
					cout<<"\t---->Substring Not Found";
					break;
			case 8: s.reverse();
					s.display();
					break;
			case 9:cout<<"Enter String to compare: ";
					s1.read();
					if(s.compare(s1))
					cout<<"\t----> Strings are Equal"<<endl;
					else
					cout<<"\t----> Strings are Not Equal"<<endl;
					break;
			case 10:cout<<"Enter The Character: ";
					cin>>c;
					s.display();
					cout<<endl;
					cout<<"\t ----> Character: "<<c<<" has occurred "<<s.frequency(c)<<" times";
					break;
			case 11:if(s.palindrome())
					cout<<"\t----> String is Palindrome"<<endl;
					else
					cout<<"\t----> String is not Palindrome"<<endl;
					break;
			case 12:cout<<"Enter character: ";
					cin>>c;
					s=s.chardelete(c);
					s.display();
					break;
			case 13:cout<<"Enter Starting Point: ";
					cin>>i;
					cout<<"Enter Span: ";
					cin>>j;
					s1=s.modify(i-1,j-1);
					if (s1.len())
					s1.display();
					else
					cout<<"\t---->NULL";
					break;
			case 0: cout<<endl<<"Exiting....";
					break;
			default:cout<<endl<<"!!!!!!Enter a valid Choice form Menu!!!!!!";
		}
		//s.menu();
		cout<<endl<<"_______________________________________________";
		cout<<endl<<"Enter Choice from Menu [Press 0 to exit]: ";
		cin>>ch;
		gets(buffer);
	}
	return 0;
}
/*
------------------STRING FUNCTIONS--------------------
	Press 1  : Enter String
	Press 2  : Display
	Press 3  : Find Length
	Press 4  : Copy
	Press 5  : concatenate
	Press 6  : find substring
	Press 7  : replace a substring
	Press 8  : Reverse the string
	Press 9  : compare with another string
	Press 10 : check frequency of any Character
	Press 11 : check Palindrome
	Press 12 : delete a character
	Press 13 : delete by index and span
	Press 0  : exit

	Enter The String: Hello World!

_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 2
	 -----> Hello World!
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 3
-----> Length Of the string is: 12
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 5
Enter The append String: DSL
	 -----> Hello World!DSL
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 4
Enter String to be copied: display multi-word string
	 -----> display multi-word string
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 6
Enter the substring:multi

yes at index value: 8,
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 7
Enter the string to be replaced: multi-
Enter the Replacement: multiple
	 -----> display multiple word string
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 8
	 -----> gnirts drow elpitlum yalpsid
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 8
	 -----> display multiple word string
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 9
Enter String to compare: display
	----> Strings are Not Equal

_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 9
Enter String to compare: display multiple word string
	----> Strings are Equal

_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 10
Enter The Character: i
	 -----> display multiple word string
	 ----> Character: i has occurred 3 times
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 11
	----> String is not Palindrome

_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 12
Enter character: r
	 -----> display multiple wod sting
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 13
Enter Starting Point: 17
Enter Span: 15
	 -----> display multiple
_______________________________________________
Enter Choice from Menu [Press 0 to exit]: 0
 */

