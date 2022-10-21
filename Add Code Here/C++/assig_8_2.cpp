#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, vector<string> board, int n)
{
    // check upper diagonal
    int irow = row;
    int icol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }
    col = icol;
    row = irow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }
    row = irow;
    col = icol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);

    return ans;
}



int main()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << "no solution exists" << endl;
    }
    else
    {
        vector<vector<string>> vec = solveNQueen(n);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j] << endl;
            }
            cout << endl;
        }
    }
    return 0;
}