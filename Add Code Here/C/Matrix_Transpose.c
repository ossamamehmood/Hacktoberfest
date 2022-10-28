#include<stdio.h>
int main()
{
    int r,c,i,j;
    printf("Enter rows : ");
    scanf("%d",&r);
    printf("Enter columns : ");
    scanf("%d",&c);
    int A[r][c],B[c][r];
    printf("Enter matrix elements : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",&A[i][j]);
    }
    printf("Matrix A : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("%d\t",A[i][j]);
        printf("\n");
    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
            B[i][j]=A[j][i];
    }
    printf("Transpose Of Matrix A : \n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        printf("%d\t",B[i][j]);
        printf("\n");
    }
}
