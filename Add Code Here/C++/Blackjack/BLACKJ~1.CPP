#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<graphics.h>

void main()
{                  int bet;
char ch,ch2;int flag=0;   int mon=500;
clrscr();
int sum=0,z,sum2=0;
char nam[20];
char dec[4]={'K','q','J','T'};

cout<<"ENTER YOUR NAME:";
gets(nam);

clrscr();
int i;                  int x1;char y1;
int x;
do{
sum=0,sum2=0;
cout<<"balance=$"<<mon<<endl;
cout<<"FOR PLAYER "<<nam<<endl;
randomize();
for(i=0;i<2;i++)
{
x=1+random(11);
char y=3+random(4);
if(x==1)
x=11;
sum+=x;
if(x==1||x==11)
{x='A';
 flag=1;
}
if(x==10)
{

z=random(3);
x=dec[z];


 }
 if(sum==22)
 {sum=12;
 }

if(isalpha(x))
cout<<char(x)<<"  "<<y<<endl;
else cout<<x<<"  "<<y<<endl;
x1=x;
y1=y;
}
	cout<<"TOTAL"<<sum;

	if(sum==21)
{
cout<<"BLACKJACK!";
  getch();
//  exit(0);
goto xy;
  }




cout<<endl<<"HIT?(Y/N)";
cin>>ch;

if(ch!='n')
{while(ch!='n')
{
 x=1+random(11);
char y=3+random(4);
if(x==1)
x=11;
sum+=x;
if(x==1||x==11)
x='A';
if(x1==x&&y1==y)
{continue;
     }
if((sum>21&&x==65)||(sum>21&&flag==1))
{sum-=10;
} flag=0;
if(x==10)
{if(y%2==0)
z=random(3);
x=dec[z];
}


if(isalpha(x))
cout<<char(x)<<"  "<<y<<endl;
else cout<<x<<"  "<<y<<endl;

	cout<<"TOTAL"<<sum<<endl;


if(sum>21)
{
cout<<"Exceeded 21!,eliminated";
getch();
//exit(0);
goto xy;
}
if(sum==21)
{
cout<<endl<<" BLACKJACK!";
 getch();
// exit(0);
 goto xy;
  }
cout<<"\nContinue?(Y/N)";
cin>>ch;
}

}
cout<<"\nYour total is "<<sum;
getch();
clrscr();
cout<<"FOR DEALER "<<endl;
randomize();
for(i=0;i<2;i++)
{
x=1+random(11);
char y=3+random(4);
if(x==1)
x=11;
sum2+=x;
if(sum2==22)
{sum2=12;
}
if(x==1||x==11)
{x='A';
 flag=1;
}
if(x==10)
{if(y%2==0)
{
z=random(3);
x=dec[z];
}

 }

if(isalpha(x))
cout<<char(x)<<"  "<<y<<endl;
else cout<<x<<"  "<<y<<endl;
x1=x;
y1=y;
}
	cout<<"TOTAL"<<sum2<<endl;

	if(sum2==21)
{
cout<<"BLACKJACK! Dealer wins";
  getch();
 // exit(0);
 goto xy;
  }
  i=0;
  if(sum2==sum)
  { cout<<"DRAW , Dealer pushes ";
  getch();
 // exit(0);
 goto xy;
  }
 if(sum2<=17&&sum2<sum)
 {
  while(i==0)
{
   cout<<"Dealer hits"<<endl;
  getch();


 x=1+random(11);
char y=3+random(4);
if(x==1)
x=11;
sum2+=x;
if(x==1||x==11)
x='A';
if(x1==x&&y1==y)
{continue;
     }
if((sum2>21&&x==65)||(sum2>21&&flag==1))
{sum2-=10;
} flag=0;
if(x==10)
{if(y%2==0)
z=random(3);
x=dec[z];
}

if(isalpha(x))
cout<<char(x)<<"  "<<y<<endl;
else cout<<x<<"  "<<y<<endl;

	cout<<"TOTAL"<<sum2<<endl;

    if(sum2>sum&&sum2<21)
    break;

if(sum2>21)
{
cout<<"Exceeded 21!,dealer eliminated  "<<nam<<" wins";
i=1;
getch();
//exit(0);
goto xy;
}
    if(sum2==sum)
  { cout<<"DRAW , Dealer pushes ";
  getch();
 // exit(0);
 goto xy;
  }
if(sum2==21)
{
cout<<" BLACKJACK! Dealer Wins";
 getch();
 //exit(0);
 goto xy;
  }
}
  }



       if(sum2>sum)
  {
 cout<<endl<<"dealer's total-"<<sum2<<" DEALER WINS" ;
   }
    else cout<<endl<<"dealer's total-"<<sum2<<" "<<nam<<"wins";
	   clrscr();
	   xy:
	   cout<<"\n\nPLAY AGAIN? (Y/N)";
	   cin>>ch2;
	   clrscr();
	   } while(ch2=='y');

 getch();
}
