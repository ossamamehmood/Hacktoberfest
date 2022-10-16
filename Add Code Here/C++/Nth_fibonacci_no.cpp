#include<iostream>
#include<vector>
using namespace std;

int output(int n, vector<int>& dp)
{
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = output(n - 1, dp) + output(n - 2, dp);
}

int fib(int n) {
    if(n < 2)
        return n;
    vector<int>dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    return output(n, dp);
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Output : "<<fib(n);
    return 0;
}
