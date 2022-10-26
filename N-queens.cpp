#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<bool> > grid, int curr_row, int y, int n)
{
    for(int row=0; row<curr_row; row++)
    {
        if(grid[row][y]==1)                            //  checking for a row
        {
            return false;
        }
    }

    int row=curr_row, col=y; 
    while(row>=0  &&  col>=0)
    {
        if(grid[row][col]==1)                          //  checking for upper left diagonal
        {
            return false;
        }
        row--;
        col--;
    }

    row=curr_row, col=y;
    while(row>=0  &&  col<=n)
    {
        if(grid[row][col]==1)                          //  checking for upper right diagonal
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void display(vector<vector<bool> > grid, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j])
            cout<<"1";

            else
            cout<<"0";
        }
        cout<<endl;
    }   
}

// to count the no. of solutions possible
int count=0;
void countnQueen(vector<vector<bool> > &grid, int curr_row, int n)
{
    if(curr_row==n){
        count++;
        display(grid, n);
        cout<<endl;
        return;
    }

    for(int col=0; col<n; col++){
        if(isSafe(grid, curr_row, col, n)){
            grid[curr_row][col]=1;
            countnQueen(grid, curr_row+1, n);
            grid[curr_row][col]=0;                    // backtracking
        }
    }
}

int main()
{
    int n;
    cin>>n;

    vector<vector<bool> > grid(n, vector<bool>(n, false));

    countnQueen(grid,0,n);
    cout<<count;

    return 0;
}
