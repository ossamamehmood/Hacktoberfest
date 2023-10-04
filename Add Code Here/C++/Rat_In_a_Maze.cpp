#include <iostream>
using namespace std;

int sol[100][100] = {0};

bool RatInaMaze(char maze[][4], int i, int j, int n, int m) {
    if (i == n - 1 && j == m - 1) {
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                cout << sol[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    sol[i][j] = 1;

    // Move right
    if (j + 1 < m && maze[i][j + 1] != 'X') {
        bool isMazeSolvedFromRight = RatInaMaze(maze, i, j + 1, n, m);
        if (isMazeSolvedFromRight == true) {
            return true;
        }
    }

    // Move down
    if (i + 1 < n && maze[i + 1][j] != 'X') {
        bool isMazeSolvedFromDown = RatInaMaze(maze, i + 1, j, n, m);
        if (isMazeSolvedFromDown == true) {
            return true;
        }
    }

    sol[i][j] = 0;
    return false;
}

int main() {
    char maze[][4] = {
        {'0', '0', '0', '0'},
        {'0', '0', 'X', 'X'},
        {'0', '0', '0', '0'},
        {'X', 'X', '0', '0'}
    };

    RatInaMaze(maze, 0, 0, 4, 4);
    return 0;
}
