#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, m2, n2, sum = 0;
    printf("No of coloum of first matrix must be equal to the no. of rows in second matrix\n ");
    printf("Enter the number of rows and coloum of your first matrix\n");
    scanf("%d %d", &m, &n);
    printf("Enter the number of rows and coloum of your first matrix\n");
    scanf("%d %d", &m2, &n2);
    if (n == m2)
    {
        int a[m][n], b[m2][n2], result[m][n2];
        printf("Enter your First matrix\n");

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Enter your second matrix\n");
        for (int i = 0; i < m2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        printf("Resultant matrix is\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                result[i][j] = sum;
                sum = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n2; j++)
            {

                printf("%d \t", result[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication of this matrix is not possible");
    }
    return 0;
}