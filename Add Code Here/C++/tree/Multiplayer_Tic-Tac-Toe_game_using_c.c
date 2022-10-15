#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
COORD coord={0,0};
char box[8];
int turn=0;
int position;


void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



void continue_game()
{
    if(position==2)
        player2();
    if(position==1)
        player1();
}




void put_x_o(int n,char c)
{
    if(n==1){
        gotoxy(32,5);
        printf("%c",c);
        box[0]=c;
    }
    else if(n==2){
        gotoxy(39,5);
        printf("%c",c);
        box[1]=c;

    }
    else if(n==3)
    {
        gotoxy(47,5);
        printf("%c",c);
        box[2]=c;
    }
    else if(n==4)
            {
                gotoxy(32,8);
                printf("%c",c);
                box[3]=c;
            }
    else if(n==5)
    {
        gotoxy(39,8);
        printf("%c",c);
        box[4]=c;
    }
    else if(n==6)
    {
        gotoxy(47,8);
        printf("%c",c);
        box[5]=c;
    }
    else if(n==7)
    {
        gotoxy(32,10);
        printf("%c",c);
        box[6]=c;
    }
    else if(n==8)
    {
        gotoxy(39,10);
        printf("%c",c);
        box[7]=c;
    }
    else if(n==9)
    {
        gotoxy(47,10);
        printf("%c",c);
        box[8]=c;
    }
    check_draw();
    check_win();
}
void check_win()
{

    int check=0;
    if(box[0]=='O' && box[1]=='O' && box[2]=='O')
        check=1;
    if(box[3]=='O' && box[4]=='O' && box[5]=='O')
        check=1;
    if(box[6]=='O' && box[7]=='O' && box[8]=='O')
        check=1;
    if(box[0]=='O' && box[3]=='O' && box[6]=='O')
        check=1;
    if(box[1]=='O' && box[4]=='O' && box[7]=='O')
        check=1;
    if(box[2]=='O' && box[5]=='O' && box[8]=='O')
        check=1;
    if(box[0]=='O' && box[4]=='O' && box[8]=='O')
        check=1;
    if(box[2]=='O' && box[4]=='O' && box[6]=='O')
        check=1;


    if(box[0]=='X' && box[1]=='X' && box[2]=='X')
        check=2;
    if(box[3]=='X' && box[4]=='X' && box[5]=='X')
        check=2;
    if(box[6]=='X' && box[7]=='X' && box[8]=='X')
        check=2;
    if(box[0]=='X' && box[3]=='X' && box[6]=='X')
        check=2;
    if(box[1]=='X' && box[4]=='X' && box[7]=='X')
        check=2;
    if(box[2]=='X' && box[5]=='X' && box[8]=='X')
        check=2;
    if(box[0]=='X' && box[4]=='X' && box[8]=='X')
        check=2;
    if(box[2]=='X' && box[4]=='X' && box[6]=='X')
        check=2;
    if(check==1)
    {
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t-------------Player 2 Win !--------------\n");
        printf("\033[0m");
        getch();
        exit(0);
    }
    if(check==2)
    {
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t--------------Player 1 Win !--------------\n");
        printf("\033[0m");
        getch();
        exit(0);
    }
}
void check_draw()
{
    if(turn==9)
    {
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t---------------Game Draw !------------------\n\n\n");
        printf("\033[0m");
        getch();
        exit(0);
    }
}
void player2()
{
    int box_n;
    check_draw();
    check_win();
    gotoxy(50,15);
    printf("\n\t\t\t\tPlayer 2 your turn :");
    printf("\n\n\t\t\t\tChose your box :");
    scanf("%d",&box_n);
    put_x_o(box_n,'O');
    box[box_n-1]='O';
    turn+=1;
    position=1;
    continue_game();
}
void player1()
{
    int box_n;
    check_draw();
    check_win();
    gotoxy(50,15);
    printf("\n\t\t\t\tplayer 1 your turn ");
    printf("\n\n\t\t\t\tChose your box :");
    scanf("%d",&box_n);
    put_x_o(box_n,'X');
    box[box_n-1]='X';
    turn+=1;
    position=2;
    continue_game();
}
void show_board()
{
    int j;
    printf("\n\t\t\t-----------Tic Tac Toe------------");
 for(j=4;j<12;j++)
 {
  gotoxy(35,j);
  printf("|       |");
 }
 gotoxy(28,6);
 printf("-----------------------");
 gotoxy(28,9);
 printf("-----------------------");
}
void Start_menu()
{
    int num;
    system("cls");
    printf("\n\t================= Tic Tac Toe ==================\n\n\n");
    printf("\t\t\tPlayer 1 : X ");
    printf("\n\t\t\tPlayer 2 : O");
    Sleep(3000);
    printf("\n\n\n\t--------------------- Menu ----------------------\n");
    printf("\n\n\t\t\t1. Play with X");
    printf("\n\t\t\t2. Play with O");
    printf("\n\t\t\t3. Exit\n");
    printf("\n\n\t\tEnter your choice:\t");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        system("cls");
        show_board();
        player1();
        break;
    case 2:
        system("cls");
        show_board();
        player2();
        break;
    case 3:
        exit(1);
    default:
        Start_menu();
    }
}
void Start_Game()
{
    for(int i=0;i<9;i++)
        box[i]=' ';
    turn=0;
    system("cls");
    system("color B9");
    Start_menu();
    getch();
}

void main()
{
    system("cls");
    Start_Game();
    getch();
    return 0;
}
