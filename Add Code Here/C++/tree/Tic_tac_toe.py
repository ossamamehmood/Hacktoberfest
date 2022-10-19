from IPython.display import clear_output

def display_board(board):
    
    print(f'{board[0]}|{board[1]}|{board[2]}\n_|_|_\n{board[3]}|{board[4]}|{board[5]}\n_|_|_\n{board[6]}|{board[7]}|{board[8]}\n')
def player_input():
    inp='Wrong'
    while inp not in ['X','O']:
        inp=input('Player 1 choose X or O ')
        if(inp not in ['X','O']):
            print('Wrong Input')
        elif inp=='X':
            player_1= 'X'
            player_2='O'
        else:
            player_2= 'X'
            player_1='O'
    return (player_1,player_2)
def place_marker(board, marker, position):
    board[position-1]=marker
    return board
def win_check(board, mark):
    if board[0]==mark:
        if (board[1]==mark and board[2]==mark) or (board[3]==mark and board[6]==mark) or (board[4]==mark and board[8]==mark):
            return True
    elif board[1]==mark:
        if (board[4]==mark and board[7]==mark):
            return True
    elif board[2]==mark:
        if (board[5]==mark and board[8]==mark) or (board[4]==mark and board[6]==mark):
            return True
    elif board[3]==mark:
        if (board[4]==mark and board[5]==mark):
            return True
    elif board[6]==mark:
        if (board[7]==mark and board[8]==mark):
            return True
    else:
        return False
        
import random

def choose_first():
    first=random.randint(1,2)
    return first
def space_check(board, position):
    if board[position-1]==' ':
        return True
    else:
        return False
def full_board_check(board):
    if ' ' in board:
        return True
    else:
        return False
def player_choice(board):
    cond=False
    choice=100
    while cond==False or choice not in range(1,10):
        choice=int(input('Enter your position choice '))
        if (choice not in range(1,10)):
            continue
        cond=space_check(board, choice)
        if(cond==False):
            print('Position invalid, choose another ')
    return choice
def replay():
    cond=False
    while cond==False:
        t=input('Do you want to play again? (Y/N)')
        cond=t in ['Y','N']
    if(t=='Y'):
        return True
    elif(t=='N'):
        return False
print('Welcome to Tic Tac Toe!')

gameon=True
while gameon:
    board=[' ',' ',' ',' ',' ',' ',' ',' ',' ']
    print('The gameboard looks like:')
    display_board(board)
    p=player_input()
    n=choose_first()
    win=False
    while(win==False):
        if(not full_board_check(board)):
            print('Its a tie')
            break
        print(f'Player {n} plays first')
        t1=player_choice(board)
        board=place_marker(board,p[n-1],t1)
        display_board(board)
        if(win_check(board,p[n-1])):
            print(f'Player{n} wins!!!')
            win=True
            break
        if(not full_board_check(board)):
            print('Its a tie')
            break
        print(f'Player {3-n} plays now')
        t2=player_choice(board)
        board=place_marker(board,p[3-n-1],t2)
        display_board(board)
        if(win_check(board,p[3-n-1])):
            print(f'Player{3-n} wins!!!')
            win=True
            break 
    gameon=replay()
