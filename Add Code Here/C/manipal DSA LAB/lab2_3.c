#include<stdio.h>
int mat_input(int arr[2][2])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Enter elements %d %d ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    return 0;
}
void main()
{
    int a[2][2],b[2][2],c[2][2];
    printf("Enter the elements of 1st 2d array");
    mat_input(a);
    mat_input(b);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("The sum of array is \n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }   
}