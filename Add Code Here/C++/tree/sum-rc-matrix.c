//WAP to find sum of rows and columns of a matrix

#include <stdio.h>

void main(){
    int m,n;
    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d",&m,&n);
    int A[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Enter the element: \n");
            scanf("%d",&A[i][j]);
        }
    }
    printf("The matrix is: \n");
    for(int i=0;i<0;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("The sum of the columns is:\n");
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++)
            sum=sum+A[i][j];
        printf("%d\t",sum);
    }
}