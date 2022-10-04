#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
	int left = 0;
	int right = n-1;
	int l_max = 0;
	int r_max = 0;
	int result = 0;
	while (left <= right)
	{
	if(r_max <= l_max)
	{
		result += max(0, r_max-arr[right]);
		r_max = max(r_max, arr[right]);
		right -= 1;
	}
	else
	{
		result += max(0, l_max-arr[left]);
		l_max = max(l_max, arr[left]);
		left += 1;
	}
	}
	return result;
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
	cout << maxWater(arr, n) << endl;
	return 0;
}
