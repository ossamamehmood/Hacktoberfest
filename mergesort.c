#include <stdio.h>
void merge(int arr[][2] ,int  si , int ei ) {
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    int i = si;
    int temp[100][2];
    int j = mid + 1;
    int index = si;
    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            temp[index][0] = arr[i][0];
            temp[index][1] = arr[i][1];
            i++;

        } else {
            temp[index][0] = arr[j][0];
            temp[index][1] = arr[j][1];
            j = j + 1;


        }
        index++;

    }
    if (i > mid) {
        while (j <= ei) {
            temp[index][0] = arr[j][0];
            temp[index][1] = arr[j][1];
            index++;
            j++;
        }
    } else {
        while (i <= mid) {
            temp[index][0] = arr[i][0];
            temp[index][1] = arr[i][1];
            index++;
            i++;


        }
    }
    int p;
    p = si;
    while (p < index) {
        arr[p][0] = temp[p][0];
        arr[p][1] = temp[p][1];
        p++;
    }
}
void mergesort(int arr[][2], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = (si + ei) / 2;
    mergesort(arr, si, mid);
    mergesort(arr, mid + 1, ei);
    merge(arr, si, ei);
}
void display(int arr[][2], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d %d  ", arr[i][0] , arr[i][1]);
        }
    printf("\n");
    }
int main() {
    int n;
    int m ;
    
    scanf("%d %d", &n ,&m);
    int arr[m][2];
    for (int i=0 ;i<m ; i++){
        int a, b;
        scanf("%d %d", &a ,&b );
        arr[i][0]=a;
        arr[i][1]=b;
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    
    mergesort(arr, 0, size - 1);
    display(arr, size);
    return 0;

}
