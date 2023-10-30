#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check for queens in the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check for queens in the right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens are placed successfully
        // Print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            res = solveNQueensUtil(board, row + 1, N) || res;

            // If placing the queen in board[row][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[row][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueensUtil(board, 0, N)) {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N for N-Queens: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
