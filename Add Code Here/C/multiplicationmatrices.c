#include<stdio.h>
int main()
{
    int r1,r2,c1,c2;
    printf("enter the row then column of matrix 1::\n");
    scanf("%d %d",&r1,&c1);
    printf("enter the row and column sequentially of matrix 2::\n");
    scanf("%d %d",&r2,&c2);
    int a[r1][c1],b[r2][c2],c[r1][c2];
    printf("enter the elements of first matrix::");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("now next row::\n");
    }
    printf("\n");
    printf("enter the elements of second matrix::");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
        printf("now next row::\n");
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            c[i][j]=0;
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            for(int k=0;k<c1;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("-----------------------------------------------------------------------------------------\n");
    printf("the matrix after multiplication will be::\n");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;

}