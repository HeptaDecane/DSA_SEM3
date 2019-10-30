#include<bits/stdc++.h>
using namespace std;
class String{
	char arr[256];
public:
	String();
	String(const String &);
	friend istream & operator >>(istream &,String &);
	friend ostream & operator <<(ostream &,String &);
	int length();
	int isSubstring(String &);
	bool replace(String &,String &);
	int concat(String &);
	bool compare(String &);
	void reverse();
	bool isPalindrome();
	int frequency(char);
	String chardelete(char c);
	String modify(int,int);
	void menu();
};
String::String(){
	arr[0]='\0';
}
String::String(const String &str){
	int i;
	for(i=0;str.arr[i]!='\0';i++)
		this->arr[i]=str.arr[i];
	arr[i]='\0';
}
istream & operator >>(istream & in,String & str){
	in.getline(str.arr,256);
	return in;
}
ostream & operator <<(ostream & out,String & str){
	out<<str.arr;
	return out;
}
int String::length(){
	int i;
	for(i=0;arr[i]!='\0';i++);
	return i;
}
int String::isSubstring(String &str){
	int flag=1;
	for(int i=0;i<=length()-str.length();i++){
		flag=1;
		for(int j=0;j<str.length();j++){
			if(arr[i+j]!=str.arr[j])
				flag=0;
		}
		if(flag)
			return i;
	}
	return -1;
}
int String::concat(String &str){
	int i,j;
	for(i=length(),j=0;str.arr[j]!='\0';i++,j++)
		arr[i]=str.arr[j];
	arr[i]='\0';
	return i;
}
bool String::replace(String &str1,String &str2){
	int index,i,j;
	String appendix;
	bool flag=false;
	index=this->isSubstring(str1);
	while(index!=-1){
		flag=true;
		for(i=index+str1.length(),j=0;arr[i]!='\0';i++,j++)    //Separating Appendix
			appendix.arr[j]=arr[i];
		appendix.arr[j]='\0';
		for(i=index,j=0;str2.arr[j]!='\0';i++,j++)    //Over-Writing Replacement
			arr[i]=str2.arr[j];
		arr[i]='\0';
		this->concat(appendix);
		index=this->isSubstring(str1);
	}
	return flag;
}
bool String::compare(String &str){
	int flag=true;
	for(int i=0;arr[i]!=0;i++)
		if(arr[i]!=str.arr[i]){
			flag=false;
			break;
		}
	return this->length()==str.length()&&flag;		
}
void String::reverse(){
	char temp;
	int n=this->length();
	for(int i=0;i<n/2;i++){
		temp=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
	arr[n]='\0';
}
bool String::isPalindrome(){
	int n=this->length();
	for(int i=0;i<n/2;i++)
		if(arr[i]!=arr[n-i-1])
			return false;
	return true;
}
int String::frequency(char c){
	int count=0;
	for(int i=0;arr[i]!='\0';i++)
		if(arr[i]==c)
			count++;
	return count;
}
String String::chardelete(char c){
	String str;
	int i=0,j=0;
	for(i=0;arr[i]!='\0';i++)
		if(arr[i]!=c){
			str.arr[j]=arr[i];
			j++;
		}
	str.arr[j]='\0';
	return str;
}
String String::modify(int start,int span){
	String str;
	int i=0,j=0;
	for(i=0;arr[i]!='\0';i++){
		if(i==start)
			i+=span;
		str.arr[j]=arr[i];
		j++;
	}
	str.arr[j]='\0';
	return str;
}
