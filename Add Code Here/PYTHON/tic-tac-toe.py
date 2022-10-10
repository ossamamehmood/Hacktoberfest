import random


class TicTacToe:

    def __init__(self):
        self.board = []

    def create_board(self):
        for i in range(3):
            row = []
            for j in range(3):
                row.append('-')
            self.board.append(row)

    def get_random_first_player(self):
        return random.randint(0, 1)

    def fix_spot(self, row, col, player):
        self.board[row][col] = player

    def is_player_win(self, player):
        win = None

        n = len(self.board)

        # checking rows
        for i in range(n):
            win = True
            for j in range(n):
                if self.board[i][j] != player:
                    win = False
                    break
            if win:
                return win

        # checking columns
        for i in range(n):
            win = True
            for j in range(n):
                if self.board[j][i] != player:
                    win = False
                    break
            if win:
                return win

        # checking diagonals
        win = True
        for i in range(n):
            if self.board[i][i] != player:
                win = False
                break
        if win:
            return win

        win = True
        for i in range(n):
            if self.board[i][n - 1 - i] != player:
                win = False
                break
        if win:
            return win
        return False

        for row in self.board:
            for item in row:
                if item == '-':
                    return False
        return True

    def is_board_filled(self):
        for row in self.board:
            for item in row:
                if item == '-':
                    return False
        return True

    def swap_player_turn(self, player):
        return 'X' if player == 'O' else 'O'

    def show_board(self):
        for row in self.board:
            for item in row:
                print(item, end=" ")
            print()

    def start(self):
        self.create_board()

        player = 'X' if self.get_random_first_player() == 1 else 'O'
        while True:
            print(f"Player {player} turn")

            self.show_board()

            # taking user input
            row, col = list(
                map(int, input("Enter row and column numbers to fix spot: ").split()))
            print()

            # fixing the spot
            self.fix_spot(row - 1, col - 1, player)

            # checking whether current player is won or not
            if self.is_player_win(player):
                print(f"Player {player} wins the game!")
                break

            # checking whether the game is draw or not
            if self.is_board_filled():
                print("Match Draw!")
                break

            # swapping the turn
            player = self.swap_player_turn(player)

        # showing the final view of board
        print()
        self.show_board()


# starting the game
tic_tac_toe = TicTacToe()
tic_tac_toe.start()
=======
from tkinter import *
from tkinter.messagebox import showinfo
import warnings
 
#Removes all the warning from the output
warnings.filterwarnings('ignore')
 
root=Tk()
 
 
numbers=[1,2,3,4,5,6,7,8,9] 
# y='X' for player1 and 'O' for player2
y=""
# x is the counter to keep counting the number of chances
x=0
#boards is a list to store the mark with respect to the cell number
boards=["board"]*10
 
def result(boards,mark):
    return ((boards[1] == boards[2] == boards [3] == mark) 
            or (boards[4] == boards[5] == boards [6] == mark) 
            or (boards[7] == boards[8] == boards [9] == mark) 
            or (boards[1] == boards[4] == boards [7] == mark) 
            or (boards[2] == boards[5] == boards [8] == mark)
            or (boards[3] == boards[6] == boards [9] == mark)
            or (boards[1] == boards[5] == boards [9] == mark) 
            or (boards[3] == boards[5] == boards [7] == mark))
 
 
def define_sign(number):
    global x,y,numbers
    """ Checking which button has been clicked and checking if the button has been already clicked or not to avoid over-writing"""
    if number==1 and number in numbers:
        numbers.remove(number)
        
        # If the value of x is even, Person1 will play and vivee versa
        if x%2==0:
            y='X'
            boards[number]=y
        elif x%2!=0:
            y='O'
            boards[number]=y
        #Using config, we write mark the button with appropriate value. 
        b1.config(text=y)
        x=x+1
        mark=y
        # Here we are calling the result() to decide whether we have got the winner or not
        if(result(boards,mark) and mark=='X' ):
            #If Player1 is the winner show a dialog box stating the winner
            showinfo("Result","Player1 wins")
            #Call the destroy function to close the GUI
            destroys()
        elif(result(boards,mark) and mark=='O'):
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==2 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
        elif x%2!=0:
            y='O'
            boards[number]=y
             
        b2.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark)and mark=='X' ):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark)and mark=='O' ):
            showinfo("Reuslt","Player2 wins")
            destroys()
         
    if number==3 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
 
        elif x%2!=0:
            y='O'
            boards[number]=y    
        b3.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark)and mark=='X'):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark) and mark=='O'):
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==4 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
         
        elif x%2!=0:
            y='O'
            boards[number]=y  
        b4.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark)and mark=='X'):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark) and mark=='O'):
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==5 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
        elif x%2!=0:
            y='O'
            boards[number]=y
                        
        b5.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark)and mark=='X' ):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,"O")and mark=='O'):
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==6 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
        elif x%2!=0:
            y='O'
            boards[number]=y
 
        b6.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark) and mark=='X'):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark)and mark=='O'):
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==7 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
 
        elif x%2!=0:
            y='O'
            boards[number]=y
 
        b7.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark) and mark=='X' ):
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark) and mark=='O'):
            print("Player2 wins")
            showinfo("Result","Player2 wins")
            destroys()
         
    if number==8 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
 
        elif x%2!=0:
            y='O'
            boards[number]=y
             
        b8.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark) and mark=='X'):
            print("Player1 wins")
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,"O")and mark=='O'):
            print("Player2 wins")
            showinfo("Result","Player2 wins")
            destroys()
    if number==9 and number in numbers:
        numbers.remove(number)
        if x%2==0:
            y='X'
            boards[number]=y
 
        elif x%2!=0:
            y='O'
            boards[number]=y
             
        b9.config(text=y)
        x=x+1
        mark=y
        if(result(boards,mark) and mark=='X'):
            print("Player1 wins")
            showinfo("Result","Player1 wins")
            destroys()
        elif(result(boards,mark) and mark=='O'):
            print("Player2 wins")
            showinfo("Result","Player2 wins")
            destroys()
             
    # If we have not got any winner, display the dialogbox stating the match has bee tied.
    if(x>8 and result(boards,'X')==False and result(boards,'O')==False):
        showinfo("Result","Match Tied")
        destroys()
         
 
 
label1=Label(root,text="player1 : X",font="times 15")
label1.grid(row=0,column=1)
 
 
l2=Label(root,text="player2 : O",font="times 15")
l2.grid(row=0,column=2)
 
 
def destroys():
    # destroys the window when called
    root.destroy()
 
 
b1=Button(root,width=20,height=10,command=lambda:define_sign(1))
b1.grid(row=1,column=1)
b2=Button(root,width=20,height=10,command=lambda:define_sign(2))
b2.grid(row=1,column=2)
b3=Button(root,width=20,height=10,command=lambda: define_sign(3))
b3.grid(row=1,column=3)
b4=Button(root,width=20,height=10,command=lambda: define_sign(4))
b4.grid(row=2,column=1)
b5=Button(root,width=20,height=10,command=lambda: define_sign(5))
b5.grid(row=2,column=2)
b6=Button(root,width=20,height=10,command=lambda: define_sign(6))
b6.grid(row=2,column=3)
b7=Button(root,width=20,height=10,command=lambda: define_sign(7))
b7.grid(row=3,column=1)
b8=Button(root,width=20,height=10,command=lambda: define_sign(8))
b8.grid(row=3,column=2)
b9=Button(root,width=20,height=10,command=lambda: define_sign(9))
b9.grid(row=3,column=3)
root.mainloop()