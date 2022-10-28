// Q2. Write a program in C to input an array and search an element using 
//linear search.
#include<stdio.h>
void main()
{
    int n,key,i,flag=1;
    printf("Enter n \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        printf("%d was found at %d ",key,i+1);
    }
    else
        printf("%d was not found ",key);
}