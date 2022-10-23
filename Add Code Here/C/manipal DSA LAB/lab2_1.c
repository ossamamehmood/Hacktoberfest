#include<stdio.h>
int main()
{
    int arr[2][7]={{33,34,35,33,32,31,30},
                   {23,22,21,24,22,25,26}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<7;j++)
        {
            printf("City %d, Day %d: %d\n",i+1,j+1,arr[i][j]);
        }
    }
    return 0;
}