//transpose general
#include <stdio.h>

void main() {
    int i,j,m,n;
    printf("Enter the number of rows and columns od the matrix: \n");
    scanf("%d,%d",&m,&n);
    int A[m][n], B[n][m];
    printf("Enter the elements of the matrix: \n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("Enter element: \n");
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++)
            B[j][i]=A[i][j];
    }
    printf("The matrix is: \n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
    printf("The transpose of the matrix is: \n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            printf("%d\t",B[i][j]);
        printf("\n");
    }
}