#include<stdio.h>
int main()
{
int ch,x,i;
scanf("%d%d",&ch,&x);
i=ch;
while(ch<=i&&i<=x)
{
if(i%2==0)
printf("\n%d",(i+1));
i++;
}
}
