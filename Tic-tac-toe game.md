# Tic-Tac-Toe Game

Tic-tac-toe is a two-player game typically played on a 3x3 grid, where players take turns marking either "X" or "O" in empty cells. The first player to get three of their marks in a row, column, or diagonal wins. If the grid is filled without a winner, the game is a draw.

## Python Implementation

Below is a simple text-based Python implementation of a tic-tac-toe game for two players:

```python
# Initialize an empty 3x3 tic-tac-toe board
board = [[' ' for _ in range(3)] for _ in range(3)]

# Function to display the current state of the board
def display_board():
    for row in board:
        print('|'.join(row))
        print('-' * 5)

# Function to check if a player has won
def check_winner(player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

# Function to play the tic-tac-toe game
def play_game():
    player = 'X'
    turns = 0

    while turns < 9:
        display_board()
        print(f"Player {player}'s turn. Enter row and column (e.g., 0 0 for the top-left cell):")
        
        try:
            row, col = map(int, input().split())
            if board[row][col] == ' ':
                board[row][col] = player
                turns += 1

                if check_winner(player):
                    display_board()
                    print(f"Player {player} wins!")
                    break

                player = 'X' if player == 'O' else 'O'
            else:
                print("That cell is already occupied. Try again.")
        except (ValueError, IndexError):
            print("Invalid input. Please enter row and column as two integers.")

    if turns == 9:
        display_board()
        print("It's a draw!")

# Start the game
play_game()
```
`Note: To end the game, press Ctrl+C or close the terminal.`
