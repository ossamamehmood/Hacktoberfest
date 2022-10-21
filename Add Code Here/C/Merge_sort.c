#include <stdio.h>

int b[10];
void merge(int *a, int lb, int mid, int ub){
    int i = lb, j = mid+1, k = lb;
    while (i<=mid && j <=ub)
    {
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    
    if(i > mid){
        while(j<=ub){
            b[k] = a[j];
            j++; k++;
        }
    }
    else if(j > ub){
        while(i<=mid){
            b[k] = a[i];
            i++; k++;
        }
    }

    for(int x= lb; x<=ub; x++){
        a[x] = b[x];
    }
}

void mergeSort(int *a, int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
    else{
        return;
    }
}


int main()
{
    int A[10] = {1, 8, 4, 7, 45, 47, 87, 12, 34, 88};
    mergeSort(A, 0, 9);

    for(int i = 0; i < 10; i++){
        printf("%d ", b[i]);
    }

    printf("\n\nA: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", A[i]);
    }
return 0;
}
