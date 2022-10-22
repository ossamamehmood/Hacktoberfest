// These are the two DSA lab questions that we need to write…
// Q1. Write a program in C to input an array and apply the following operations in it:
// i)	Display
// ii)	Insertion
// iii)	Deletion
#include<stdio.h>
void main()
{
    int n,i,ind;
    printf("Enter n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    printf("Enter the element to be deleted");
    scanf("%d",&ind);
    for(i=ind;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}