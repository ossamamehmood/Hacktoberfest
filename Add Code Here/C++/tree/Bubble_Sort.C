#include<stdio.h>
#include<conio.h>
void main()
{
 int n,i,j,a[100],t;
 printf("Enter the no of elements you need to sort");
 scanf("%d",&n);
 printf("Enter the elements:");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=n;i>0;i--)
 {
  for(j=1;j<i;j++)
  {
   if(a[j]<a[j-1])
   {
    t=a[j];
    a[j]=a[j-1];
    a[j-1]=t;
   }
  }
 }
 printf("The sorted array is:\n");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 getch();
}
