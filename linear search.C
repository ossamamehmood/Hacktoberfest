#include<stdio.h>

int linearsearch(int x,int *arr){
    int n, i = 0;
    for(i = 0; i<n; i++){
        if(arr[i] == x){
            printf("Element is found");
            break;
        }
        if(i>=x){
            printf("Element is not found");
            break;
        }
    }

    /*if(i>=x){
        printf("Element is not found");
    }*/
}

int main(){
    int n,x;
    int arr[100];
    printf("Enter the no. of content present in an array: \n");
    scanf("%d", &n);
    printf("Enter the element: \n");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Which element will be found: ");
    scanf("%d",&x);

    linearsearch(x, arr);
    return 0;
}
