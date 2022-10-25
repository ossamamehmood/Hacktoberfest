#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 6

void merge_sort(int, int);
void merge_array(int, int, int, int);

int Arr[MAX_SIZE];

int main() {
  int i;

  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &Arr[i]);

  printf("\nEnter the elements   :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", Arr[i]);
  }

  merge_sort(0, MAX_SIZE - 1);

  printf("\n\nResult after merge sorting :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", Arr[i]);
  }
  getch();

}

void merge_sort(int i, int j) {
  int mid;

  if (i < j) {
    mid = (i + j) / 2;
    merge_sort(i, mid);
    merge_sort(mid + 1, j);
    merge_array(i, mid, mid + 1, j);
  }
}

void merge_array(int a, int b, int c, int d) {
  int tmp[50];
  int i = a, j = c, k = 0;

  while (i <= b && j <= d) {
    if (Arr[i] < Arr[j])
      tmp[k++] = Arr[i++];
    else
      tmp[k++] = Arr[j++];
  }

  while (i <= b)
    tmp[k++] = Arr[i++];

  while (j <= d)
    tmp[k++] = Arr[j++];

  for (i = a, j = 0; i <= d; i++, j++)
    Arr[i] = tmp[j];
}