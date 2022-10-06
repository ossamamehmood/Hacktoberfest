#include<stdlib.h>
#include<stdio.h>


void display_array(int size, int a[]){
    for (int i = 0; i < size; i++)
    {
        printf("%d   ", a[i]);
    }
    printf("\n");
}

int max_element(int array[], int count){
    int max=0;
    for (int i = 0; i < count; i++)
    {
        
        if(array[i]>max)
            max=array[i];
    }
    return max;
}

int * countsort(int A[], int B[], int size){
    int max=max_element(A, size);
    int C[max+1];
    for(int i=0; i<=max; i++){
        C[i]=0;
    }
    display_array(max+1, C);
    for (int i = 0; i <size; i++)
    {
        C[A[i]]=C[A[i]]+1;
    }
    display_array(max+1, C);
    for(int i=1; i<=max; i++){
        C[i]=C[i]+C[i-1];
    }
    display_array(max+1, C);
    for (int i = size-1; i>=0; i--)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]-=1;
    }
    return B;
}
int main(){
    printf("Enter array size    :\n");
    int size;
    scanf("%d", &size);
    int array[size];
    printf("Enter elements of array  :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    display_array(size, array);
    int B[size];
    int *c=countsort(array, B, size);
    display_array(size, c);

}
