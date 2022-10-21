//50) To find out second largest element of an unsorted array.
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a[5],i,j,max,max1;
 printf("Enter the array elements:");
     for(i=0;i<5;i++)
     {
        scanf("%d",&a[i]);
     }
        max=a[0];
     for(i=0;i<5;i++)
     {
         if(max<a[i])
         max=a[i];
     }
    max1=a[0];
     for(j=1;j<5;j++)
     {
         if(a[j]>max1 && a[j]<max)
         max1=a[j];
     }
 printf("second large is %d",max1);
 return 0;
}
