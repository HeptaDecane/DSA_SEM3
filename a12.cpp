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
	float array[MAX];
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
	shellSort();
	int j=n-1,count=0;
	cout<<"\nTop Five Scores: ";
	while(j>=0&&count<5){
		cout<<array[j]<<" ";
		count++;
		while(array[j]==array[j-1])
			j--;
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
void Database::display(){
	cout<<"\nArray of Marks: \n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<"\n";
}
void Database::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Enter Score Array";
	cout<<"\nPress 2: Sort Scores by Bubble Sort";
	cout<<"\nPress 3: Sort Scores by Selection Sort";
	cout<<"\nPress 4: Sort Scores by Insertion Sort";
	cout<<"\nPress 5: Sort Scores by Shell Sort";
	cout<<"\nPress 6: Display Top Five Scores";
	cout<<"\nPress 7: Display Score Array";	
	cout<<"\nPress 9: Display Operations";
}
int main(){
	Database result;
	int choice,key;
	result.menu();
	do{
		cout<<endl<<"____________________________________________________";
		cout<<endl<<"Enter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: result.setData();
					break;
			case 2: cout<<"\nSorted by Bubble Sort!";
					result.bubbleSort();
					break;
			case 3: cout<<"\nSorted by Selection Sort!";
					result.selectionSort();
					break;
			case 4: cout<<"\nSorted by Insertion Sort!";
					result.insertionSort();
					break;
			case 5: cout<<"\nSorted by Shell Sort!";
					result.shellSort();
					break;
			case 6: result.topFive();
					break;
			case 7: result.display();
					break;
			case 9: result.menu();
					break;
			case 0: cout<<"\n----------------------END---------------------------\n";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);	
	return 0;
}
