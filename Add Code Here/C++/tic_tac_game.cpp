#include<iostream>
#include<stdlib.h>
// #include<windows.h>
using namespace std;
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
bool checkRows(char symbol);
bool isWinner(char symbol);
int gridSize=3;
char board[3][3]={{' ',' ',' '},
                  {' ',' ',' '},
                  {' ',' ',' '}};
int main()
{
    int count=0;
    string  player1,player2;
    cout<<"enter player one name:";
    cin>>player1;
    cout<<"enter player 2 name:";
    cin>>player2;
    int number=0;
    int loopcounter=0;
    int c=0;
    int count1=0;
    while(true)
    {
        for(int i=0;i<gridSize*gridSize;i++)
        {
            loopcounter++;
            int num1,num2;
            system("Color 9F");
            cout<<"     -----------------------"<<endl;
            cout<<"1    :"<<board[0][0]<<"     |   "<<board[0][1]<<"   |   "<<board[0][2]<<"  :"<<endl;
            cout<<"     :_____________________:"<<endl;
            cout<<"2    :"<<board[1][0]<<"     |   "<<board[1][1]<<"   |   "<<board[1][2]<<"  :"<<endl;
            cout<<"     :_____________________:"<<endl;
            cout<<"3    :"<<board[2][0]<<"     |   "<<board[2][1]<<"   |   "<<board[2][2]<<"  :"<<endl;
            cout<<"     :_____________________:"<<endl;
            cout<<"     ----------------------"<<endl;
            if(count1 == 0)
            {
                system("Color 0A");
                cout<<"player 1 "<<player1<<endl;
                count1=1;
            }
            else 
            {
                system("Color 0E");
                cout<<"player 2 "<<player2<<endl;
                count1=0;
            }
            cout<<"enter row number:"<<endl;
            cin>>num1;
            if(num1 > 2)
            {
                continue;
            }
            cout<<"enter coulomn number:"<<endl;
            cin>>num2;
            if(num2>2)
            {
                continue;
            }
            system("cls");
            if(board[num1][num2] == ' ')
            if(count == 0)
            { 
                board[num1][num2]='*';
                bool result=checkDiagonals('*');
                if(result == 1)
                {
                    cout<<"game winner is "<< player1<<endl;
                    number=1;
                    break;
                }
                result=checkRows('*');
                if(result == 1)
                {
                    cout<<"game winner is "<< player1<<endl;
                    number=1;
                    break;
                }
                result=checkColumns('*');
                if(result == 1)
                {
                    cout<<"game winner is "<< player1<<endl;
                    number=1;
                    break;
                }
                count=1;
            }
            else 
            {
                bool result=checkDiagonals('0');
                if(result == 1)
                {
                    cout<<"game winner is "<< player2<<endl;
                    number=2;
                    break;
                }
                result=checkRows('0');
                if(result == 2)
                {
                    cout<<"game winner is "<< player2<<endl;
                    number=2;
                    break;
                }
                result=checkColumns('0');
                if(result == 1)
                {
                    cout<<"game winner is "<< player2<<endl;
                    number=2;
                    break;
                }
                board[num1][num2]='0';
                count=0;
                if(loopcounter >= 9)
                break;
            }
            if(loopcounter >= 9)
                break;
            if(number == 1 || number == 2)
                break;
        }
        if(loopcounter >= 9)
                break;
        if(number == 1 || number == 2)
             break;
        if(loopcounter >= 9)
        {
            cout<<"no one is winner:"<<endl;
        }
    }
    if(c == 0)
    {
        system("Color 0D");
        cout<<"     -----------------------"<<endl;
        cout<<"1    :"<<board[0][0]<<"     |   "<<board[0][1]<<"   |   "<<board[0][2]<<"  :"<<endl;
        cout<<"     :_____________________:"<<endl;
        cout<<"2    :"<<board[1][0]<<"     |   "<<board[1][1]<<"   |   "<<board[1][2]<<"  :"<<endl;
        cout<<"     :_____________________:"<<endl;
        cout<<"3    :"<<board[2][0]<<"     |   "<<board[2][1]<<"   |   "<<board[2][2]<<"  :"<<endl;
        cout<<"     :_____________________:"<<endl;
        cout<<"     ----------------------"<<endl;
    }
    return 0;
}
bool checkRows(char symbol){
 int count = 0;
 for(int row = 0; row < gridSize; row = row + 1)
 {
 count = 0;
 for(int col = 0; col < gridSize; col = col + 1)
 {
 if(board[row][col] == symbol){
 count = count + 1;
 }
 }
 if(count == gridSize)
 {
 return 1;
 }
 }
 return 0;
}
bool checkColumns(char symbol){
 int count = 0;
 for(int col = 0; col < gridSize; col = col + 1)
 {
 count = 0;
 for(int row = 0; row < gridSize; row = row + 1)
 {
 if(board[row][col] == symbol){
 count = count + 1;
 }
 }
 if(count == gridSize)
 {
 return 1;
 }
 }
 return 0;
}
bool checkDiagonals(char symbol){
 int count = 0;
 for (int idx = 0; idx < gridSize; idx = idx + 1){
 if (board[idx][idx] == symbol){
 count = count + 1;
 }
 }
 if (count == gridSize){
 return 1;
 }
 count = 0;
 for (int row = 0, col = 2; row < gridSize; row++, col--){
 if (board[row][col] == symbol){
 count = count + 1;
 }
 }
 if (count == gridSize){
 return 1;
 }
 return 0;
}
bool isWinner(char symbol)
{
 if(checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
 {
 return 1;
 }
 else
 {
 return 0;
 }
}