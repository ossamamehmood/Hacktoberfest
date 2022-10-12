#include<stdio.h>
void main()
{
    int arr[8][8];
    int put=1;
    int i,j;
    int m=7;
    arr[0][0]=put;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%2d ",put);

              arr[i][j]=put++;
        }printf("\n");
    }

    printf("elements in diagonal traversal \n");
    int k;
    for(k =m;k>=0;k--)
    {
        i=k;
        j=0;
        while(i<=m)
        {
            printf("%d ",arr[i][j]);
            i++;
            j++;
        }
        printf("\n");
    }

    for(k=1;k<=m;k++)
    {
        i=0;
        j=k;
        while(j<=m)
        {
            printf("%d ",arr[i][j]);
            i++;
            j++;}
            printf("\n");

    }

}

//output
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
elements in diagonal traversal
57
49 58
41 50 59
33 42 51 60
25 34 43 52 61
17 26 35 44 53 62
9 18 27 36 45 54 63
1 10 19 28 37 46 55 64
2 11 20 29 38 47 56
3 12 21 30 39 48
4 13 22 31 40
5 14 23 32
6 15 24
7 16
8

--------------------------------
Process exited after 1.134 seconds with return value 8
Press any key to continue . . .
