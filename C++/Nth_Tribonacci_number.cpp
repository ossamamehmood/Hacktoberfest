#include<iostream>
#include<vector>
using namespace std;

int output(int n, vector<int>&dp)
{
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = output(n - 1, dp) + output(n - 2, dp) + output(n - 3, dp);
}

int tribonacci(int n) {
    if(n == 0)
        return 0;
    if(n <= 2)
        return 1;
    vector<int>dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    return output(n, dp);
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Output : "<<tribonacci(n);
    return 0;
}
