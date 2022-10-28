#include<stdio.h>
int mat_input(int r,int c,int arr[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter elements %d %d ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    return 0;
}
int main()
{
    int r1,c1,r2,c2,r3,c3,i,j,k;
    printf("Enter the row and colums of 1st matrix and than that of 2nd matrix");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if(c1==r2)
    {
        int a[r1][c2],b[r2][c2],c[r1][c2];
        mat_input(r1,c1,a);
        mat_input(r2,c2,b);
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                c[i][j]=0;
                for(k=0;k<r1;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d",c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}