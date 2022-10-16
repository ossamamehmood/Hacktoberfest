// Longest Increasing subsequence of an array using DynamicProgramming
#include <bits/stdc++.h>
using namespace std;

int longest_increasing_subsequence(int arr[], int n)
{
	vector<int>v(n);
    
    int ans;
	v[0] = 1;
    for (int i = 1; i < n; i++) {
		v[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && v[i] < v[j] + 1)
				v[i] = v[j] + 1;
	}


	ans = *max_element(v.begin(),v.end());
    return ans;
}


int main()
{
    int n;
    cout << "Enter no of array elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Enter the size of longest increasing subsequence : " << longest_increasing_subsequence(arr,n);

	

	return 0;
}
