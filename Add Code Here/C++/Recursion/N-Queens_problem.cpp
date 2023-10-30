#include <iostream>
#include <vector>

bool IsSafe(const std::vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||           // Check for the same column
            board[i] - i == col - row || // Check for left diagonal
            board[i] + i == col + row)   // Check for right diagonal
        {
            return false;
        }
    }
    return true;
}

void SolveNQueens(std::vector<std::vector<std::string>>& solutions, std::vector<int>& board, int row, int n) {
    if (row == n) {
        // All queens are successfully placed, add the solution
        std::vector<std::string> solution(n, std::string(n, '.'));
        for (int i = 0; i < n; i++) {
            solution[i][board[i]] = 'Q';
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (IsSafe(board, row, col)) {
            board[row] = col;
            SolveNQueens(solutions, board, row + 1, n);
            board[row] = -1; // Backtrack
        }
    }
}

std::vector<std::vector<std::string>> SolveNQueens(int n) {
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> board(n, -1);
    SolveNQueens(solutions, board, 0, n);
    return solutions;
}

int main() {
    int n;
    std::cout << "Enter the value of N: ";
    std::cin >> n;

    std::vector<std::vector<std::string>> solutions = SolveNQueens(n);

    if (solutions.empty()) {
        std::cout << "No solutions found for N = " << n << std::endl;
    } else {
        std::cout << "Solutions for N = " << n << ":\n";
        for (const auto& solution : solutions) {
            for (const std::string& row : solution) {
                std::cout << row << '\n';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
