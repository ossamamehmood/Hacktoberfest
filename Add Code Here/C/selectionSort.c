#include<stdio.h>
void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}
void selectionSort(int A[], int n){
    int i, j, k;
    for (i=0; i<n; i++){
        for (j=k=i; j<n; j++){
            if (A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[j], &A[k]);
    }
}
int main(){
    int n, A[100];
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for (int l=0; l<n; l++){
        scanf("%d", &A[l]);
    }
    selectionSort(A, n);
    printf("The array elements are:\n");
    for (int m=0; m<n; m++){
        printf("%d ", A[m]);
    } 
    return 0;
}