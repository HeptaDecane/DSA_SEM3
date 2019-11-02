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
	int partition(int,int);
	void quickSort(int,int);
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
int Database::partition(int low,int high){
	float pivot=array[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(array[j]>pivot){
			i++;
			swap(&array[i],&array[j]);
		}
	}
	i++;
	swap(&array[i],&array[high]);
	return i;
}
void Database::quickSort(int low,int high){
	if(low<high){
		int ptr=partition(low,high);
		quickSort(low,ptr-1);
		quickSort(ptr+1,high);
	}
}
int main(){
	int n;
	cout<<"\nEnter Array Size: ";
	cin>>n;
	Database container(n);
	container.read();
	container.quickSort(0,n-1);
	container.display();
	return 0;
}














