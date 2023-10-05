def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("---------")

def check_winner(board):
    # Check rows, columns, and diagonals
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != ' ':
            return board[i][0]  # row win
        if board[0][i] == board[1][i] == board[2][i] != ' ':
            return board[0][i]  # column win

    if board[0][0] == board[1][1] == board[2][2] != ' ':
        return board[0][0]  # diagonal win
    if board[0][2] == board[1][1] == board[2][0] != ' ':
        return board[0][2]  # diagonal win

    return None  # no winner yet

def tic_tac_toe():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    player = 'X'
    winner = None

    while ' ' in [cell for row in board for cell in row] and not winner:
        print_board(board)
        print(f"Player {player}, enter your move (row[0-2] column[0-2]):")
        row, col = map(int, input().split())

        if board[row][col] == ' ':
            board[row][col] = player
            winner = check_winner(board)
            player = 'O' if player == 'X' else 'X'
        else:
            print("Cell already taken. Try again.")

    print_board(board)
    if winner:
        print(f"Player {winner} wins!")
    else:
        print("It's a draw!")

if _name_ == "_main_":
    tic_tac_toe()
