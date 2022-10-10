#include<stdio.h>

int key;

int binarySearch(int arr[], int n){
    int start=0, end=n;
    printf("Enter the key: ");
    scanf("%d", &key);
    while (start<=end){
        int mid=(start+end)/2;
        if (arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the no. of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for (int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int x = binarySearch(arr,n);
    if (x==-1)
        printf("The key %d is not present in the array.", key);
    else
        printf("The key %d is present at index %d", key,x);
    return 0;
}