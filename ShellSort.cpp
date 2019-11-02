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
	void ShellSort();
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
void Database::ShellSort(){
	for(int gap=n/2;gap>0;gap=gap/2){
		for(int j=gap;j<n;j++){
			for(int i=j-gap;i>=0;i=i-gap){
				if(array[i+gap]>array[i])
					break;
				else
					swap(&array[i+gap],&array[i]);
			}
//			cout<<"\n";
//			for(int k=0;k<n;k++)
//				cout<<array[k]<<" ";
		}
//		cout<<"\n";
	}
}
int main(){
	int n;
	cout<<"\nEnter Array Size: ";
	cin>>n;
	Database container(n);
	container.read();
	container.ShellSort();
	container.display();
	return 0;
}














