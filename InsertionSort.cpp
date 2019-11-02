#include<bits/stdc++.h>
using namespace std;
class Database{
	int n;
	float *array;
public:
	Database();
	Database(int);
	void read();
	void display();
	void swap(float*,float*);
	void insertionSort();
};
Database::Database(){
	n=0;
	array=NULL;
}
Database::Database(int n){
	this->n=n;
	array=new float[this->n];
}
void Database::read(){
	cout<<"\nEnter Array Elements: ";
	for(int i=0;i<n;i++)
		cin>>array[i];
}
void Database::display(){
	cout<<"\nArray: ";
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
}
void Database::swap(float *a,float *b){
	float temp=*a;
	*a=*b;
	*b=temp;
}
void Database::insertionSort(){
	float temp;
	int j;
	for(int i=1;i<n;i++){
		temp=array[i];
		for(j=i-1;temp<array[j]&&j>=0;j--)
			array[j+1]=array[j];
		array[j+1]=temp;
	}
}
int main(){
	int n;
	cout<<"\nEnter Array Size: ";
	cin>>n;
	Database container(n);
	container.read();
	container.insertionSort();
	container.display();
	return 0;
}














