#include<stdio.h>
#include<conio.h>
int main()
{
    int a[20],i,j,n,temp;
    printf("Enter the Number of elements in Array : ");
    scanf("%d",&n);
    printf("Enter the Values of Array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
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
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    return 0;
}