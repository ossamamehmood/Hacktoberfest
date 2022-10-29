  from random import randint
    
    while True:
        BOARD_SIZE = 3
        board = [i for i in range(9)]
        is_winner = False
        current_player = randint(0, 1)
        markers = {0: 'O', 1: 'X'}
        available_turns = (x for x in range(9))
    
        def draw_board():
            res = ""
            for i, v in enumerate(board):
                res += str(v) + " "
                if (i+1) % BOARD_SIZE == 0:
                     res += "\n"
            print(res)
    
        def validate(value = " "):
            if not value.isdigit() and int(value) not in available_turns:
                raise ValueError ("Enter valid value and try again")
            if board[int(value)] in ('X', 'O'):
                raise ValueError ("This value has already played")
            if '.' in value:
                raise ValueError('Number must be int')
    
        def check_winner():
            current_marker = markers[current_player]
            if board[0] == current_marker and board[4] == current_marker and board[8] == current_marker or \
                    board[2] == current_marker and board[4] == current_marker and board[6] == current_marker or \
                    board[0] == current_marker and board[1] == current_marker and board[2] == current_marker or \
                    board[3] == current_marker and board[4] == current_marker and board[5] == current_marker or \
                    board[6] == current_marker and board[7] == current_marker and board[8] == current_marker or \
                    board[0] == current_marker and board[3] == current_marker and board[6] == current_marker or \
                    board[1] == current_marker and board[4] == current_marker and board[7] == current_marker or \
                    board[2] == current_marker and board[5] == current_marker and board[8] == current_marker:
                return True
            else:
                return False
    
        for i in range(9):
            try:
                input_error = True
                draw_board()
                while input_error:
                    choice = input(f"Player {markers[current_player]} enter your number:\n")
                    validate(choice)
                    input_error = False
                board[int(choice)] = markers[current_player]
                if current_player == 1:
                    
                 #проверить победителя
                is_winner = check_winner()
                if is_winner == True:
                    print(f'Player {markers[current_player]} won the game!!')
                    break
                current_player = 0 if current_player == 1 else 1
                # if is_winner == True:
            except ValueError as ex:
                print(ex)
    
        if is_winner == False:
            print('Draw')
        replay = input("Желаете переиграть? (Y or N)")
        if replay == "Y":
            continue
        else:
            break
