def check(ChessBoard):
    z=-1
    x=-1
    for i in range(8):
        chessboard=ChessBoard[i]
        try:
            z=chessboard.index('♚')
        except:
            continue
    for i in range(8):
        chessboard=ChessBoard[i]
        try:
            x=chessboard.index('♔')
        except:
            continue    
    if(z>=0 and x>=0):
        return 1
    else:
        return 0   
def pawn(ChessBoard,a,b,c,d):
    if(a-c==b-d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==1 and b==d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==d-b):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '   
def bishop(ChessBoard,a,b,c,d):
    if(a-c==b-d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==d-b):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '    
    elif(c-a==b-d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==d-b):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
def rook(ChessBoard,a,b,c,d):
    if(a==c):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(b==d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
def king(ChessBoard,a,b,c,d):
    if(a==c and b-d==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a==c and d-b==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(b==d and a-c==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(b==d and c-a==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==1 and b-d==1):
         ChessBoard[c][d]=ChessBoard[a][b]
         ChessBoard[a][b]=' '
    elif(a-c==1 and d-b==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==1 and b-d==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==1 and d-b==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
def queen(ChessBoard,a,b,c,d):
    if(a==c):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(b==d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==b-d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==d-b):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '    
    elif(c-a==b-d):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==d-b):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
def knight(ChessBoard,a,b,c,d):
    if(a-c==1 and d-b==2):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==1 and d-b==2):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==2 and b-d==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==2 and d-b==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(c-a==1 and b-d==2):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==1 and b-d==2):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==2 and b-d==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
    elif(a-c==2 and d-b==1):
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '
def printchess(ChessBoard):
        print("",ChessBoard[0][0],"|",ChessBoard[0][1],"|",ChessBoard[0][2],"|",ChessBoard[0][3],"|",ChessBoard[0][4],"|",ChessBoard[0][5],"|",ChessBoard[0][6],"|",ChessBoard[0][7])
        print("--------------------------------")
        print("",ChessBoard[1][0],"|",ChessBoard[1][1],"|",ChessBoard[1][2],"|",ChessBoard[1][3],"|",ChessBoard[1][4],"|",ChessBoard[1][5],"|",ChessBoard[1][6],"|",ChessBoard[1][7])
        print("---------------------------------")
        print("",ChessBoard[2][0],"|",ChessBoard[2][1],"|",ChessBoard[2][2],"|",ChessBoard[2][3],"|",ChessBoard[2][4],"|",ChessBoard[2][5],"|",ChessBoard[2][6],"|",ChessBoard[2][7])
        print("---------------------------------")
        print("",ChessBoard[3][0],"|",ChessBoard[3][1],"|",ChessBoard[3][2],"|",ChessBoard[3][3],"|",ChessBoard[3][4],"|",ChessBoard[3][5],"|",ChessBoard[3][6],"|",ChessBoard[3][7])
        print("---------------------------------")
        print("",ChessBoard[4][0],"|",ChessBoard[4][1],"|",ChessBoard[4][2],"|",ChessBoard[4][3],"|",ChessBoard[4][4],"|",ChessBoard[4][5],"|",ChessBoard[4][6],"|",ChessBoard[4][7])
        print("---------------------------------")
        print("",ChessBoard[5][0],"|",ChessBoard[5][1],"|",ChessBoard[5][2],"|",ChessBoard[5][3],"|",ChessBoard[5][4],"|",ChessBoard[5][5],"|",ChessBoard[5][6],"|",ChessBoard[5][7])
        print("---------------------------------")
        print("",ChessBoard[6][0],"|",ChessBoard[6][1],"|",ChessBoard[6][2],"|",ChessBoard[6][3],"|",ChessBoard[6][4],"|",ChessBoard[6][5],"|",ChessBoard[6][6],"|",ChessBoard[6][7])
        print("---------------------------------")
        print("",ChessBoard[7][0],"|",ChessBoard[7][1],"|",ChessBoard[7][2],"|",ChessBoard[7][3],"|",ChessBoard[7][4],"|",ChessBoard[7][5],"|",ChessBoard[7][6],"|",ChessBoard[7][7])
                                                

ChessBoard=[['♜','♞','♝','♛','♚','♝','♞','♜'],['♟','♟','♟','♟','♟','♟','♟','♟'],[' ',' ',' ',' ',' ',' ',' ',' '],[' ',' ',' ',' ',' ',' ',' ',' '],[' ',' ',' ',' ',' ',' ',' ',' '],[' ',' ',' ',' ',' ',' ',' ',' '],['♙','♙','♙','♙','♙','♙','♙','♙'],['♖','♘','♗','♕','♔','♗','♘','♖']]

printchess(ChessBoard)
s=check(ChessBoard)
print("White's turn is first and then Black's and then the game continues until any one of the kings is dead")
while(s==1):
    a=int(input("enter initial row"))
    b=int(input("enter initial column "))
    c=int(input("enter final row "))
    d=int(input("enter final column "))
    if( ChessBoard[a][b]=='♙'):
        pawn(ChessBoard,a,b,c,d)         
    elif(ChessBoard[a][b]=='♜' or ChessBoard[a][b]=='♖'):
        rook(ChessBoard,a,b,c,d)  
    elif(ChessBoard[a][b]=='♞' or ChessBoard[a][b]=='♘'):
        knight(ChessBoard,a,b,c,d)
    elif(ChessBoard[a][b]=='♝' or ChessBoard[a][b]=='♗'):
        bishop(ChessBoard,a,b,c,d)
    elif(ChessBoard[a][b]=='♚' or ChessBoard[a][b]=='♔'):
        king(ChessBoard,a,b,c,d)  
    elif(ChessBoard[a][b]=='♛' or ChessBoard[a][b]=='♕'):
        queen(ChessBoard,a,b,c,d)
    else:
        ChessBoard[c][d]=ChessBoard[a][b]
        ChessBoard[a][b]=' '    
    printchess(ChessBoard)
    s=check(ChessBoard)
    if(s==0):
        print("Game ends")
