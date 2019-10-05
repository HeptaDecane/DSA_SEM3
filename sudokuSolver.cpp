#include<bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 9
class Sudoku{
	int grid[N][N]={
						{3, 0, 6,   0, 0, 8,   4, 0, 0},  
                    	{0, 8, 0,   0, 1, 0,   7, 2, 0},  
                    	{2, 0, 0,   0, 4, 0,   0, 0, 9},  
                    	
                    	{5, 0, 7,   0, 0, 9,   0, 1, 0},  
                    	{0, 0, 0,   0, 3, 0,   0, 9, 0},  
                    	{0, 3, 0,   0, 5, 0,   2, 0, 7}, 
                    	 
                    	{1, 0, 8,   0, 0, 4,   0, 0, 0},  
                    	{0, 0, 0,   0, 0, 0,   0, 4, 8},  
                    	{9, 2, 0,   1, 0, 7,   3, 0, 0}
                   };  
public:
	void setGrid();
	void printGrid();
	bool usedInRow(int row,int num);
	bool usedInCol(int col,int num);
	bool usedInBox(int boxRow,int boxCol,int num);
	bool isSafe(int row,int col,int num);
	bool findUnassignedLocation(int &row,int &col);
	bool solveSudoku();
};
void Sudoku::printGrid(){
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++){
			cout<<grid[row][col]<<" ";
			if((col+1)%3==0)
				cout<<"  ";
		}
		cout<<"\n";
		if((row+1)%3==0)
			cout<<"\n";
	}
}
bool Sudoku::usedInRow(int row, int num){
	for(int col=0;col<N;col++)
		if(grid[row][col]==num)
			return true;
	return false;
}
bool Sudoku::usedInCol(int col,int num){
	for(int row=0;row<N;row++)
		if(grid[row][col]==num)
			return true;
	return false;
}
bool Sudoku::usedInBox(int boxRow,int boxCol,int num){
	for(int row=0;row<3;row++)
		for(int col=0;col<3;col++)
			if(grid[boxRow+row][boxCol+col]==num)
				return true;
	return false;
}
bool Sudoku::isSafe(int row,int col,int num){
	return (	!usedInRow(row,num)&&
				!usedInCol(col,num)&&
				!usedInBox(row-row%3,col-col%3,num)&&
				grid[row][col]==UNASSIGNED
		   );
}
bool Sudoku::findUnassignedLocation(int &row,int &col){
	for(row=0;row<N;row++)
		for(col=0;col<N;col++)
			if(grid[row][col]==UNASSIGNED)
				return true;
	return false;
}
bool Sudoku::solveSudoku(){
	int row,col;
	if(!findUnassignedLocation(row,col))
		return true;
	//cout<<row<<" "<<col<<"\n";
	for(int num=1;num<=9;num++){
		if(isSafe(row,col,num)){
			grid[row][col]=num;
			if(solveSudoku())
				return true;
			grid[row][col]=UNASSIGNED;
		}
	}
	return false;
}
int main(){
	Sudoku s;
	if(s.solveSudoku()==true)
		s.printGrid();
	else
		cout<<"\nNo Solution Exists!";
	return 0;
}		





