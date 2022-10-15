#include<stdio.h>
#include<conio.h>
void main()
{ 
clrscr();
   int a[ ]={ 2,3,4,5,1 },i,x,c,flag=1;
printf(“ enter value to be searched … ”);
scanf(“%d”,&x);
   for(i=0;i<5,i++) 
   { 
if( a[i]==x)
        flag=1;
break ;
       count=count+1;
    }

 count=count+1;
if(flag==1)
printf(“ value found ”);
else 
printf(“ value not found ”);
getch();
}
