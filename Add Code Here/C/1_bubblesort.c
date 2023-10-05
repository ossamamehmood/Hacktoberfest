#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubblesort(int *arr, int n){
    
int i,j;

for(i=0;i<n-1;i++){
    int flag = 0;
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            flag = 1;
        }
    }
    if(flag==0)
        break;
}

}

void display(int *arr,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d, ",arr[i]);

    printf("\n");
    
}

int main(){


int *arr,n,i;
printf("Enter number of elements in array: ");
scanf("%d", &n);

arr=(int *)malloc(sizeof(int)*n);

printf("Enter elements of array: ");
for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

display(arr,n);
bubblesort(arr,n);
display(arr,n);



}