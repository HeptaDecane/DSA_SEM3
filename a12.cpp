//============================================================================
// Name        : Assignment12.cpp
// Author      : near
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
class Database{
	int array[MAX];
	int n;
public:
	Database();
	void setData();
	void display();
	void selectionSort();
	void bubbleSort();
	void insertionSort();
	void shellSort();
	void topFive();
	void menu();
};
Database::Database(){
	for(int i=0;i<MAX;i++)
		array[i]=0;
	n=0;
}
void Database::selectionSort(){
	float min,temp;
	int loc;
	for(int i=0;i<n-1;i++){
        min=array[i];
        loc=i;
        for(int j=i+1;j<n;j++){
            if(min>array[j]){
                min=array[j];
                loc=j;
            }
        }
        temp=array[i];
        array[i]=array[loc];
        array[loc]=temp;
    }
}
void Database::bubbleSort(){
	float temp;
	for(int i=1;i<n;++i){
		for(int j=0;j<(n-i);++j){
			if(array[j]>array[j+1]){
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
			}
		}
	}
}
void Database::insertionSort(){
	float temp;
	int j;
    for(int i=1;i<=n-1;i++)
    {
        temp=array[i];
        j=i-1;

        while((temp<array[j])&&(j>=0))
        {
            array[j+1]=array[j];    //moves element forward
            j=j-1;
        }

        array[j+1]=temp;    //insert element in proper place
    }
}
void Database::shellSort(){
	int gap,i,j;
	float temp;
	for(gap=n/2;gap>0;gap/=2){
		if(gap%2==0)		//optimization technique
			gap++;
		for(i=gap;i<n;i+=1){
			temp=array[i];
			for(j=i;j>=gap&&array[j-gap]>temp;j-=gap){
				array[j]=array[j-gap];
			}
			array[j]=temp;
		}
	}
}
void Database::topFive(){
	int j=n-1,count=0;
	while(j>0&&count<5){
		cout<<array[j]<<" ";
		count++;
		j--;
		while(array[j]==array[j-1])
			j--;
	}
}
void Database::setData(){
	cout<<"\nEnter No. of Students: ";
	cin>>n;
	for(int i=0;i<n;i++){
label:
		cout<<"\nEnter Marks for Roll No. "<<i+1<<": ";
		cin>>array[i];
		if(array[i]<0||array[i]>100){
			cout<<"\nError: Invalid Value for Percentage!\nTry Again!\n";
			goto label;
		}
	}
}
int main(){
	Database result;
	result.setData();
	result.topFive();
}
