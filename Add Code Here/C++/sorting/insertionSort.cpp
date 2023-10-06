#include <bits/stdc++.h>
using namespace std;
void print (int *arr, int size)
{
  for (int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void insertionSort (int *arr, int size)
{
  int key, j;
  for (int i=1; i<size; i++)
  {
    key = arr[i];
    j = i;
    while (j>0 && arr[j-1]>key)
    {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = key;
   }
}
int main() 
{
  int n;
  cin >> n;
  int a[n];
  for (int i=0; i<n; i++)
  {
    cin >> a[i];
  }
  cout << "Array before Sorting : ";
  print(a, n);
  insertionSort(a, n);
  cout << "Array after Sorting : ";
  print(a, n);
}
