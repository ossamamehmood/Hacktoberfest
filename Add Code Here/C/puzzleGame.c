#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 


void initializeBoard(int board[][SIZE]) {
    int i, j;
    int num = 1;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
    
    // Set the last element as 0 (empty)
    board[SIZE - 1][SIZE - 1] = 0;
}

// Function to display the puzzle board
void displayBoard(int board[][SIZE]) {
    int i, j;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("  ");
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if the puzzle is solved
int isSolved(int board[][SIZE]) {
    int i, j;
    int num = 1;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != num++) {
                return 0; // Not solved
            }
        }
    }
    
    return 1; // Solved
}

// Function to swap the empty cell with a neighboring cell
void swap(int board[][SIZE], int row1, int col1, int row2, int col2) {
    int temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
}

int main() {
    int board[SIZE][SIZE];
    char move;
    int row, col;
    int moves = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    initializeBoard(board);
    
    // Shuffle the board by making random moves
    for (int i = 0; i < 1000; i++) {
        int randomMove = rand() % 4; // 0: Up, 1: Down, 2: Left, 3: Right
        int emptyRow, emptyCol;
        
        // Find the position of the empty cell
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    emptyRow = row;
                    emptyCol = col;
                    break;
                }
            }
        }
        
        // Perform a random move (if valid)
        switch (randomMove) {
            case 0: // Up
                if (emptyRow > 0) {
                    swap(board, emptyRow, emptyCol, emptyRow - 1, emptyCol);
                }
                break;
            case 1: // Down
                if (emptyRow < SIZE - 1) {
                    swap(board, emptyRow, emptyCol, emptyRow + 1, emptyCol);
                }
                break;
            case 2: // Left
                if (emptyCol > 0) {
                    swap(board, emptyRow, emptyCol, emptyRow, emptyCol - 1);
                }
                break;
            case 3: // Right
                if (emptyCol < SIZE - 1) {
                    swap(board, emptyRow, emptyCol, emptyRow, emptyCol + 1);
                }
                break;
        }
    }
    
    printf("Welcome to the Number Puzzle Game!\n");
    
    while (1) {
        displayBoard(board);
        
        if (isSolved(board)) {
            printf("Congratulations! You solved the puzzle in %d moves.\n", moves);
            break;
        }
        
        printf("Enter your move (W/A/S/D for Up/Left/Down/Right, Q to quit): ");
        scanf(" %c", &move);
        
        if (move == 'Q' || move == 'q') {
            printf("Quitting the game.\n");
            break;
        }
        
        // Find the position of the empty cell
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    break;
                }
            }
            if (board[row][col] == 0) {
                break;
            }
        }
        
        switch (move) {
            case 'W':
            case 'w': // Up
                if (row > 0) {
                    swap(board, row, col, row - 1, col);
                    moves++;
                }
                break;
            case 'A':
            case 'a': // Left
                if (col > 0) {
                    swap(board, row, col, row, col - 1);
                    moves++;
                }
                break;
            case 'S':
            case 's': // Down
                if (row < SIZE - 1) {
                    swap(board, row, col, row + 1, col);
                    moves++;
                }
                break;
            case 'D':
            case 'd': // Right
                if (col < SIZE - 1) {
                    swap(board, row, col, row, col + 1);
                    moves++;
                }
                break;
            default:
                printf("Invalid move. Please use W/A/S/D to move or Q to quit.\n");
        }
    }
    
    return 0;
}
