#include <stdio.h>

int main(){
    int m, n, p, q;
    // printf("Enter the order of 1st matrix(a, b): ");
    scanf("%d %d", &m, &n);
    int mat1[m][n];

    scanf("%d %d", &p, &q);
    int mat2[p][q];

    


    // printf("\n\nEnter values of matrix 1--\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("Enter the (%d, %d) element: ", i+1, j+1);
            scanf("%d", &mat1[i][j]);
        }
    }
    // printf("\n\nEnter values of matrix 2--\n\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            // printf("Enter the (%d, %d) element: ", i+1, j+1);
            scanf("%d", &mat2[i][j]);
        }
    }

    if(p!=n){
        printf("-1");
        return 0;
    }

    int multiply[p][q];

    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < q; b++)
        {
            multiply[a][b] = 0;
            for (int i = 0; i < n; i++)
                {
                    multiply[a][b] += mat1[a][i]*mat2[i][b];
            }
        } 
        
    }


    // Printing Matrix 
    printf("\n\nMultiplying both matrix we get--\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d\t", multiply[i][j]);
        }
        printf("\n");
    }

    int max = multiply[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if(multiply[i][j]>=max)
                max = multiply[i][j];
        }
    }
    printf("\n\n%d", max);


    return 0;
}
