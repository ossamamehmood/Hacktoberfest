/ Trace of the matrix
// Trace of the matrix is called sum of the elements in a principle diagonal of the square matrix.

#include<stdio.h>

int main(){
    int i,j,n;
    printf("Enter the size of square matrix: ");
    scanf("%d",&n);
    int arr[n][n],sum=0;

    // input
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          scanf("%d",&arr[i][j]);

    for(i=0;i<n;i++){
                sum+=arr[i][i];
            }

    printf("Trace of the matrix is: %d",sum);

}
