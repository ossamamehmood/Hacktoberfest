#include <bits/stdc++.h>
using namespace std;
//simple travelling that works for square matrix
void recur_travel(int mat[4][4],int row,int col,int n){
	if(row == n && col == n)
		return; // base condition
	mat[row][col] = 1; //marking visited cells
	recur_travel(mat,row+1,col+1,n); //resursion travels to row+1, col+1
	//if the matrix is not square this will fail and end up in memory error as 
	//the stack will keep on building and never have the base condition
	//p.s. just for explaination
}
int main() {
	// your code goes here
	int mat[4][4];
	memset(mat,0,sizeof(mat));
	recur_travel(mat,0,0,4); //calling recur function
	//print the path matrix
	for(int i = 0;i<4;i++)
		{
			for(int j = 0;j<4;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	return 0;
}
