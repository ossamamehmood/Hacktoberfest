#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int count = 0;
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void maxheapify(int *arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = (2*i) + 2;

    if(l<n && arr[l]>arr[largest]){
        largest = l;
        count++;
    }
    
    if(r<n && arr[r]>arr[largest]){
        largest = r;
        count++;
    }

    if(largest!=i){
        swap(&arr[largest], &arr[i]);
        maxheapify(arr,n,largest);
    }
}

void heapsort(int *arr, int n) {

    for(int i=n/2-1;i>=0;i--)
        maxheapify(arr,n,i);
    for(int i=n-1;i>=1;i--)
    {
        swap(&arr[i], &arr[0]);
        maxheapify(arr, i , 0);
    }
}

void display(int *arr,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d, ",arr[i]);

    printf("\n");
    
}
int main(){

srand(time(0));
int *arr,n;
printf("Enter number of elements in array: ");
scanf("%d", &n);

arr = (int *)malloc(sizeof(int)*n);

for(int i=0;i<n;i++){
    arr[i] = rand()%100;
}

display(arr,n);
heapsort(arr,n);
printf("Resulting Array: ");
display(arr,n);
printf("No. of comparisons: %d \n",count);


}