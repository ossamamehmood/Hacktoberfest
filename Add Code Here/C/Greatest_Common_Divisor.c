#include<stdio.h>
void main()
{  int n1,n2,t,i;
   printf("Enter The Two Numbers \n");
   scanf("%d%d",&n1,&n2);
   if(n2>n1)
   {t = n1;
    n1= n2;
    n2 = t;}
    for(i = n2;i>0;i--)
    {if(n1%i==0&&n2%i==0)
    {  printf("%d \n",i);
        break;}
}
}
