
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int subsetSum(int a[], int n, int sum)
{

    if (sum == 0)
        return 1;

    if (n <= 0)
        return 0;

    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];

    if (a[n - 1] > sum)
        return dp[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {

        return dp[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                                subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

int main()
{

    memset(dp, -1, sizeof(dp));
    int n;
    cout << "Enter the size of the array:- " << endl;
    cin >> n;
    int a[n];
    int sum;
    cout << "Enter the Target Sum" << endl;
    cin >> sum;
    cout << "Enter the elements of the array :-" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
