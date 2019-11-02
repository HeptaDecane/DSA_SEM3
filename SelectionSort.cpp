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
	void selectionSort();
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
void Database::selectionSort(){
	float min;
	int loc;
	for(int i=0;i<n-1;i++){
		min=array[i];
		loc=i;
		for(int j=i+1;j<n;j++){
			if(array[j]<min){
				min=array[j];
				loc=j;
			}
		}
		swap(&array[i],&array[loc]);
	}
}
int main(){
	int n;
	cout<<"\nEnter Array Size: ";
	cin>>n;
	Database container(n);
	container.read();
	container.selectionSort();
	container.display();
	return 0;
}














