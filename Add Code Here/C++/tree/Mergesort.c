#include <stdio.h>


void merge_sort(int i, int j, int a[], int a1[]) {
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;



    merge_sort(i, mid, a, a1);
    merge_sort(mid + 1, j, a, a1);

    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;


    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            a1[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            a1[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            a1[k] = a[pointer_left];
            pointer_left++;
        } else {
            a1[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = a1[k];
    }
}


int main() {
  int a[100], a1[100], n, i, d, swap;

  printf("Enter number of elements in the array:\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  merge_sort(0, n - 1, a, a1);

  printf("Printing the sorted array:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);

  return 0;
}
