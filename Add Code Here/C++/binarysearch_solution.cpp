#include <iostream>
using namespace std;

int bs(int a[], int x, int l, int h) {
  while (l <= h) {
    int mid = l + (h - l) / 2;

    if (a[mid] == x)
      return mid;

    if (a[mid] < x)
      l = mid + 1;

    else
      h = mid - 1;
  }

  return -1;
}

int main() {
  int a[100], n, x;
  cout<<"Enter size of array: ";
  cin>>n;
  cout<<"Enter array elements: ";
  for(int i=0;i<n;i++)
      cin>>a[i];
  cout<<"Enter element you want to find: ";
  cin>>x;
  int res = bs(a, x, 0, n - 1);
  if (res == -1)
    cout<<"Element not found";
  else
    cout<<"Element is found at index "<<res;
}