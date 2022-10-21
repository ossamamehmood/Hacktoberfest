#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void main()
{        clrscr();
	int gd=DETECT, gm;
	int x1,x2,y1,y2,dx,dy,steps,xinc,yinc;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	cout<<"Enter the starting coordinates:"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the end coordinates:"<<endl;
	cin>>x2>>y2;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	steps=abs(dx);
	else
	steps=abs(dy);
	
	xinc=dx/steps;
	yinc=dy/steps;

	for(int i=0;i<steps;i++)
	{
	putpixel(x1,y1,3);
	x1=x1+xinc;
	y1=y1+yinc;
	delay(100);
	}
	getch();
	closegraph();
	}

