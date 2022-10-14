#include <stdio.h>
#include <stdlib.h>
int crosssubsum(int a[], int low, int mid, int high)
{
  int leftsum = 0, rightsum = 0, sum = 0, i;
  for (i = mid; i >= low; i--)
  {
    sum = sum + a[i];
    if (sum > leftsum)
      leftsum = sum;
  }
  sum = 0;
  for (i = mid + 1; i <= high; i++)
  {
    sum = sum + a[i];
    if (sum > rightsum)
      rightsum = sum;
  }
  return leftsum + rightsum;
}
int maxsubsum(int a[], int low, int high)
{
  int mid, leftsum, rightsum, crosssum;
  if (low == high)
    return a[low];
  mid = (low + high) / 2;
  leftsum = maxsubsum(a, low, mid);
  rightsum = maxsubsum(a, mid + 1, high);
  crosssum = crosssubsum(a, low, mid, high);
  if (leftsum >= rightsum && leftsum >= crosssum)
    return leftsum;
  else if (rightsum >= leftsum && rightsum >= crosssum)
    return rightsum;
  else
    return crosssum;
}
int main()
{

  int n, a[10], i, low, high, maxsum;
  printf("Enter the no. of Elements\n");
  scanf("%d", &n);
  printf("Enter an Array of +ve and -ve No.\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  low = 0;
  high = n - 1;
  maxsum = maxsubsum(a, low, high);
  printf("Maximum Contiguous Sum = %d\n", maxsum);
  return 0;
}