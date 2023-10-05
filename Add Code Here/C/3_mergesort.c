#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void merge(int *arr,int lb,int mid,int ub){
    int i=lb,j=mid+1, index=lb,k=lb;
    int temp[ub];
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            temp[index]=arr[i];
            i++;
        }
        else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=ub){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else {
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }

    for(k=lb;k<=ub;k++)
        arr[k]=temp[k];

}

void mergesort(int *arr,int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;

    mergesort(arr,lb,mid);
    mergesort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
    }
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);

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
mergesort(arr,0,n-1);
display(arr,n);


}