// code for tic-tac-toe game

#include <iostream>
using namespace std;

// for creating dynamic numbers and changeable to mark of player 1 and 2
char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void printBoard(){

    // System is function used to pass the command to terminal
    system("cls");

    cout<<endl<<" --Tic Tac Toe--"<<endl<<endl;
    cout<<"     |     |     "<<endl;
    // cout<<"  1  |  2  |  3  "<<endl;
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    // cout<<"  4  |  5  |  6  "<<endl;
    cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    // cout<<"  7  |  8  |  9  "<<endl;
    cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
}

int checkWin(){
    // Horizontal winning cases
    if(board[0]==board[1] && board[1]==board[2]){
        return 1;
    }
    if(board[3]==board[4] && board[4]==board[5]){
        return 1;
    }
    if(board[6]==board[7] && board[7]==board[8]){
        return 1;
    }
    // Vertical winning cases
    if(board[0]==board[3] && board[3]==board[6]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    // two cross winning cases
    if(board[0]==board[4] && board[4]==board[8]){
        return 1;
    }
    if(board[2]==board[4] && board[4]==board[6]){
        return 1;
    }

    // checking if all 9 boxes filled up or not 
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if(board[i] == 'X' || board[i] == 'O'){
            count++;
        }
    }
    // if filled then draw the match 
    if(count == 9){
        return 0;
    }
    
}
int main()
{
    // The default player turn
    int player = 1;
    
    // input for marking players move and status for looping the game
    int input, status = -1;

    printBoard();

    while(status==-1){

        // to update the turn of each player
        if(player%2==0){
            player = 2;
        }
        else{
            player = 1;
        }

        
        cout<<endl<<"Enter input Player - "<<player<<" : ";
        cin>>input;

        // to update the mark of each player 
        char mark;
        if(player==1){
            mark = 'X';
        }
        else{
            mark = 'O';
        }

        // Handling invalid move inputs
        if(input>9 || input<1){
            cout<<"Invalid input!";
            break;
        }

        // updating mark of each player at the given input number (input - 1 => because of our array started with 0)
        board[input-1] = mark;

        // to see the mark updated board
        printBoard();

        // to check who wins or its a draw...
        int result = checkWin();
        if(result==1){
            cout<<endl;
            cout<<"Game Result : ";
            cout<<"Winner -> Player "<<player<<endl;
            status = 1;
        }
        else if(result == 0){
            cout<<endl;            
            cout<<"Game Result : ";
            cout<<"Draw"<<endl;
            break;    // or we can also update status as above to break loop
        }

        // to give turn to next player
        player++;
    }

    return 0;
}