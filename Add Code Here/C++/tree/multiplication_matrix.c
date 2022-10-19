//For multiplication of two matrices.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10][10],b[10][10],c[10][10], m,n,i,j,sum=0;

    printf("enter values for m and n:\t");
    scanf("%d\t%d",&m,&n);

    printf("Enter first matrix elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d" ,&a[i][j]);
        }
    }

    printf("Enter second matrix elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d" ,&b[i][j]);
        }
    }

     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
                c[i][j]=a[i][j]*b[i][j];
                 printf("sum of diagonal elements is:%d\t",sum);
        }
    }
    return 0;
}

