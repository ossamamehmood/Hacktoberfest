#include <iostream>
using namespace std;

int maxPerimeterDP(int **arr, int i, int s, int **dp) {
	if(i==0) {
		return arr[i][s];
	}
	if(dp[i][s] != -1) return dp[i][s];
	// Case 1
	return dp[i][s] = max(maxPerimeterDP(arr, i-1, 0, dp)+arr[i][s]+abs(arr[i][(s+1)%2]-arr[i-1][1]), maxPerimeterDP(arr, i-1, 1, dp)+arr[i][s]+abs(arr[i][(s+1)%2]-arr[i-1][0]));

}

int maxPerimeter(int **arr, int i, int s) {
	if(i==0) {
		return arr[i][s];
	}

	// Case 1
	return max(maxPerimeter(arr, i-1, 0)+arr[i][s]+abs(arr[i][(s+1)%2]-arr[i-1][1]), maxPerimeter(arr, i-1, 1)+arr[i][s]+abs(arr[i][(s+1)%2]-arr[i-1][0]));

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[2];
	}
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		arr[i][0] = a;
		arr[i][1] = b;
	}
	int MAX = 1001;
	int **dp = new int*[MAX];
	for(int i=0;i<MAX;i++) {
		dp[i] = new int[2];
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	// cout<<max(maxPerimeter(arr, n-1, 0), maxPerimeter(arr, n-1, 1));
	cout<<max(maxPerimeterDP(arr, n-1, 0, dp), maxPerimeterDP(arr, n-1, 1, dp));
	return 0;
}
