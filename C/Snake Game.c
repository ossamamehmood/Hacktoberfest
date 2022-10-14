#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#define T 2000
int n=0,px,py;
main()
{
 int gd=DETECT,gm,i,j;
 clrscr();
 gotoxy(25,4);
 printf("DON'T TUCH THE BORDER");
 gotoxy(25,6);
 printf("Press < p > for pause");
 gotoxy(17,8);
 printf("IN MIDDLE OF GAME, PRESS < Esc > TO EXIT");
 x:
 gotoxy(26,10);
 printf("press < s > to start ");
 gotoxy(26,12);
 printf(" Use SMALL case only");
 gotoxy(34,10);
 if(getch()=='s')
 initgraph(&gd,&gm,"c:\tc\bgi");
 else {
 clrscr();
 goto x;
 }
 line(0,0,0,479);
 line(0,0,639,0);
 line(639,0,639,479);
 line(0,479,639,479);
 pause();
 print();
 right(100,100);
}
 right(int x,int y)
 {
 char ch,fu='r';
 int i,j;
 for(i=x;i<=652;i++){
 for(j=y;j<=y+10;j++){
 putpixel(i,j,4);
 putpixel(i-10,j,16);
 }
 delay(T-n);
 check(i,j-1);
 if(kbhit()){
 ch=getch();
 if(ch=='p')
 pause();
 else
 choice(i,j-1,ch,fu);
 }
 }
 }
 left(int x,int y)
 {
 char ch,fu='l';
 int i,j;
 for(i=x;i>-12;i--){
 for(j=y;j<=y+10;j++){
 putpixel(i,j,4);
 putpixel(i+10,j,16);
 }
 delay(T-n);
 check(i,j-1);
 if(kbhit()){
 ch=getch();
 if(ch=='p')
 pause();
 else
 choice(i,j-1,ch,fu);
 }
 }
 }
 down(int x,int y)
 {
 char ch,fu='d';
 int i,j;
 for(j=y;j<=492;j++){
 for(i=x;i<=x+10;i++){
 putpixel(i,j,4);
 putpixel(i,j-10,16);
 }
 delay(T-n);
 check(i-1,j);
 if(kbhit()){
 ch=getch();
 if(ch=='p')
 pause();
 else
 choice(i-1,j,ch,fu);
 }
 }
 }
 up(int x,int y)
 {
 char ch,fu='u';
 int i,j;
 for(j=y;j>=-12;j--){
 for(i=x;i<=x+10;i++){
 putpixel(i,j,4);
 putpixel(i,j+10,16);
 }
 delay(T-n);
 check(i-1,j);
 if(kbhit()){
 ch=getch();
 if(ch=='p')
 pause();
 else
 choice(i-1,j,ch,fu);
 }
 }
 }
 choice(int i,int j,char ch,char fu)
 {
 if(fu=='r'){
 if(ch=='K'){
 j-=10;
 i-=10;
 left(i,j);
 }
 else if(ch=='P'){
 i-=10;
 down(i,j);
 }
 else if(ch=='H'){
 j-=10;
 i-=10;
 up(i,j);
 }
 else if(ch==27)
 esc();
 else {
 j-=10;
 right(i,j);
 }
 }
 else if(fu=='l'){
 if(ch=='M'){
 j-=10;
 /*i+=-10; no comments here free me*/
 right(i,j);
 }
 else if(ch=='P')
 down(i,j);
 else if(ch=='H'){
 j-=10;
 up(i,j);
 }
 else if(ch==27)
 esc();
 else {
 j-=10;
 left(i,j);
 }
 }
 else if(fu=='d'){
 if(ch=='H'){
 j-=10;
 i-=10;
 up(i,j);
 }
 else if(ch=='K'){
 i-=10;
 j-=10;
 left(i,j);
 }
 else if(ch=='M'){
 j-=10;
 right(i,j);
 }
 else if(ch==27)
 esc();
 else {
 i-=10;
 down(i,j);
 }
 }
 else if(fu=='u'){
 if(ch=='P'){
 j+=10;
 i-=10;
 down(i,j);
 }
 else if(ch=='M')
 right(i,j);
 else if(ch=='K'){
 i-=10;
 left(i,j);
 }
 else if(ch==27)
 esc();
 else {
 i-=10;
 up(i,j);
 }
 }
 }
check(int i,int j)
{
if (n>T-1750) {
gotoxy(7,5);
printf("U r Great U got Good Score, If possible Please Develop this game");
 gotoxy(24,7);
 printf("Press ENTER Key To Continue");
 getchar();
 esc();
 }
 if(i<3 || i>637 || j<3 || j>477){
 outtextxy(240,240,"YOU HAVE TOUUCHED THE BORDER");
 outtextxy(280,280,"GAME OVER");
 outtextxy(240,370,"Better Luck Next Time");
 outtextxy(200,310,"<press ENTER Key to continue>");
 getchar();
 esc();
 }
 else if(tuch(i,j)){
 rub();
 bell();
 n+=10;
 stage();
 print();
 }
 }
 int tuch(int i,int j)
 {
 int x=px,y=py,t,s,flag=0;
 for(t=x;t<=x+15;t++){
 for(s=y;s<=y+15;s++)
 if(j==s && i==t)
 flag=1;
 }
 return(flag);
 }
 rub()
 {
 setcolor(16);
 outtextxy(px,py,"¦");
 setcolor(15);
 }
 bell()
 {
 int i;
 for(i=1;i<=5;i++){
 sound(200*i);
 delay(10000);
 nosound();
 }
 }
 stage()
 {
 gotoxy(60,5);
 printf("U got %d points",n);
 sleep(1);
 gotoxy(60,5);
 printf(" ");
 }
 print()
 {
 px=random(636);
 py=random(460);
 if(px<10)
 px+=10;
 if(py<10)
 py+=10;
 outtextxy(px,py,"¦");
 }
 pause()
 {
 outtextxy(200,470,"< Press Any Key To Continue >");
 getch();
 setcolor(16);
 outtextxy(200,470,"< Press Any Key To Continue >");
 setcolor(15);
 }
 esc()
 {
 gotoxy(20,18);
 printf(" THANK YOU ");
 gotoxy(20,20);
 printf(" < Press any key to continue > ");
 getch();
 closegraph();
 exit(0);
 }
