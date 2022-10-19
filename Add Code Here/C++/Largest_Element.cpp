#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n)
{
	return *max_element(arr, arr+n);
}

int main()
{
  int n;
  cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
    cin >> arr[i];
	cout << largest(arr, n);
	return 0;
}
