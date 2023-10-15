#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};
char currentPlayer = 'X';
int moves = 0;

void displayBoard() {
    system("clear"); // Use "cls" for Windows
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

bool isMoveValid(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

int main() {
    int move;

    while (true) {
        displayBoard();

        if (moves == 9 || checkWin()) {
            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                cout << "It's a draw!" << endl;
            }
            break;
        }

        cout << "Player " << currentPlayer << ", enter a valid move (1-9): ";
        cin >> move;

        if (!isMoveValid(move)) {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
    }

    return 0;
}
