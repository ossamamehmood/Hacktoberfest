#include<stdio.h>
#include<stdlib.h>

struct array{
    int *A;
    int size;
};


void InsertionSort(int B[],int size){
    
    for(int i=1;i<size;i++){
       int j=i-1;
       int x=B[i];
       while(j>-1 && B[j]>x){
           B[j+1]=B[j];
           j--;
       }
       B[j+1]=x;
    }
}

int main(){
int B[]= {11,13,7,12,16,9,24,5,10,3,__INT32_MAX__};

InsertionSort(B,10);

for (int i = 0; i < 10; i++)
{
    printf("%d ",B[i]);
}

return 0;

}