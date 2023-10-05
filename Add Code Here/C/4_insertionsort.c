#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void insertionsort(int *arr, int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int temp = arr[i];
		while(j>=0 && temp<arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}



int main()
{
int *arr,n,i;
printf("Enter number of elements in array: ");
scanf("%d", &n);

arr=(int *)malloc(sizeof(int)*n);

printf("Enter elements of array: ");
for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

display(arr,n);
insertionsort(arr,n);
display(arr,n);



return 0;
}