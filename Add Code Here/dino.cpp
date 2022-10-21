#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define Mx getmaxx()
#define My getmaxy()
#include <direct.h>
#include <windows.h>

int main()
{
    int gd,gm,i=0,h=0;
    L:detectgraph(&gd,&gm);
    initgraph(&gd,&gm,(char *)"");
    getch();
    int x=Mx-20,y=Mx;
    char ch;
    void *left,*right,*up;
    //Creating Images
    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,120);
    rectangle(107,110,112,120);

    rectangle(93,128,98,145);
    rectangle(101,128,106,135);
    left = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,left);

    cleardevice();
    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,120);
    rectangle(107,110,112,120);

    rectangle(93,128,98,135);
    rectangle(101,128,106,145);
    right = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,right);

    cleardevice();
    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,120);
    rectangle(107,110,112,120);
    rectangle(93,128,98,145);
    rectangle(101,128,106,145);

    up = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,up);
    cleardevice();
    void *object[3];
    //images loaded in array
    while(i<3)
    {
        cleardevice();
        setcolor(WHITE);
        rectangle(1,137,10+10*i,145);
        setfillstyle(1,4+i);
        floodfill(2,138,WHITE);
        object[i]=malloc(imagesize(0,136,10+10*i+1,146));
        getimage(0,136,10+10*i+1,146,object[i]);
        i++;
        printf("\n\t\t\t\t\t\t\t\t\t\tIMAGES STILL LOADING....");
    }
    printf("\n\t\t\t\t\t\t\t\t\t\t------------------------START------------------------");
    puts("\n\t\t\t\t\t\t\t\t\t\tSam's Status :- \n");
    int jump=0,j=0;
    i=0;
    while(1)
    {
        cleardevice();
        char a[10]="";
        itoa(i,a,10);
        if(i%100==0)
            Beep(4000,100);
        outtextxy(400,100,a);
        itoa(h,a,10);
        outtextxy(450,100,a);
        if(x<=0)
        {
            x=Mx-20;
            y=Mx;
            j++;
            j%=3;
        }
        line(0,146,Mx,146);
        if(kbhit())
        {
            ch = getch();

            if(ch==' ')
            {
                Beep(1000,10);
                jump=1;

                printf("\n\t\t\t\t\t\t\t\t\t\t\tSam Take Jump....!");
            }
        }
        if(jump==1)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\tSam is in Air....!");
            int p=92;
            while(p>20)
            {
                putimage(86,p,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                delay(0.1);
                putimage(86,p--,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                if(p%8==1)
                {x-=2;
                y-=2;
                if(p%5==0)printf("\n\t\t\t\t\t\t\t\t\t\t\t....Air....!");
                }
            }
            while(p<92)
            {
                putimage(86,p,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                delay(0.1);
                putimage(86,p++,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                if(p%8==1)
                {x-=2;
                y-=2;
                if(p%5==0)printf("\n\t\t\t\t\t\t\t\t\t\t\t....Air....!");
                }
            }
            jump=0;
            printf("\n\t\t\t\t\t\t\t\t\t\t\tSam Landed....!");
        }
        else if(i%2==0)
        {
            putimage(86,92,left,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            if(!jump)delay(50);
            putimage(86,92,left,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            x-=8;
            y-=8;
        }
        else
        {
            putimage(86,92,right,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            if(!jump)delay(50);
            putimage(86,92,right,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            x-=8;
            y-=8;
        }
        if(x>=80&&y<=120&&jump==0)
        {
            Beep(7000,1000);
            closegraph();
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tSam is Trapped....!!!!");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tBetter Luck Next time....!!\n\n\n\n\n\n\n\n\n\n");
            int d;
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tDo You Want to play Again : ");
            scanf("%d",&d);
            if(i>h)
            {
                h=i;
            }
            if(d==1)
                goto L;
            else
                break;
        }
        if(i%10==0)printf("\n\t\t\t\t\t\t\t\t\t\tCloser....");
        i++;
        j%=5;
    }
    return 0;
}