#include <stdio.h>
#include <string.h>
void printArray(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int arr[] = {0, 1, 1, 3, 2, 5, 8, 2, 7, 3, 8, 9, 5, 9, 2, 9};
  int RANGE = 10;
  int N = sizeof(arr)/4;
  int count[RANGE] = {0};
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    count[arr[i]]++;
	//printArray(count, RANGE);
  }
  for(int i = 1 ; i < RANGE ; i++){
	count[i] =  count[i-1] + count[i];
  }
  printArray(count, RANGE);
  int brr[sizeof(arr)/4];
  for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]);  i++) {
	brr[--count[arr[i]]]  = arr[i];
  }
  printArray(arr , N);
  printArray(brr, N);
  return 0;
}
