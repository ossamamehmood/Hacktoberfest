#include <iostream>
using namespace std;

// Define the dimensions of the maze
const int ROWS = 4;
const int COLS = 4;

// Define the maze using a 2D character array
char maze[ROWS][COLS] = {
    {'.', '#', '#'},
    {'.', 'S', '#'},
    {'#', '.', '.'},
    {'#', '#', 'E'}
};

// Function to check if a cell is valid (within bounds and not a wall)
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#');
}

// Recursive function to solve the maze
bool solveMaze(int row, int col) {
    // Base case: if we reach the endpoint, the maze is solved
    if (maze[row][col] == 'E') {
        return true;
    }

    // Mark the current cell as visited
    maze[row][col] = 'V'; // 'V' indicates visited

    // Explore all possible directions (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (isValid(newRow, newCol) && maze[newRow][newCol] != 'V') {
            // Recursively explore the next cell
            if (solveMaze(newRow, newCol)) {
                return true;
            }
        }
    }

    // If none of the directions lead to a solution, backtrack
    maze[row][col] = '.'; // Mark as unvisited
    return false;
}

int main() {
    int start_row, start_col;

    // Find the start point
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    if (solveMaze(start_row, start_col)) {
        cout << "Maze is solvable!" << endl;
    } else {
        cout << "Maze is unsolvable!" << endl;
    }

    return 0;
}
