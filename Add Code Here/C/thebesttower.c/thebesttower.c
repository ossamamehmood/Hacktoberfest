#include<stdio.h>

int main()

{

   int t,a,b,c,n,i,x1,x2;

   scanf("%d",&t);

   while(t>0)

   {

       scanf("%d%d%d",&a,&b,&c);

       scanf("%d",&n);

       for(i=0;i<n;i++)

	 scanf("%d%d",&x1,&x2);

       printf("%d.000 %d.000 %d.000\n",a,b,c);

       t--;

   }

   return 0;

} 
