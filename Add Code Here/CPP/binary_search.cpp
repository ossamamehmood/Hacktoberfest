#include <iostream>
using namespace std;

int binary_Search(int array[], int x, int lo, int hi) {
  

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (array[mid] == x)
      return mid;

    else if (array[mid] < x)
      lo = mid + 1;

    else
      hi = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 84, 105, 69, 47, 8, 98};
  int x = 105;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binary_Search(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is at index %d", result);
}

