//Write a prgm to implement binary search
#include<stdio.h>
void main()
{
int a[50],i,j,n,elt,temp,flag=0,low=0,high,mid;
printf("\n\tBINARY SEARCH");
printf("\n\t_______________\n\n");
printf("\n\tEnter the limit:");
scanf("%d",&n);
printf("\n\tEnter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n\n\tThe elements are:");
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\n\n\tThe sorted array is");
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
printf("\n\n\tEnter the element to be searched:");
scanf("%d",&elt);
high=n-1;
while(low=high)
{
mid=(low+high)/2;
if(elt<a[mid])
{
high=mid-1;
}
else if(elt>a[mid])
{
low=mid+1;
}
else
{
printf("\n\n\tThe element is present");
flag=1;
break;
}
}
if(flag==0)
{
printf("\n\n\tThe element is not present");
}
}
