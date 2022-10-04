#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int eggBreak(int e, int f, vector<vector<int>> &dp){

    if(f == 0 or f == 1)
        return f;

    if(e == 1)
        return f;

    if(dp[e][f] != -1)
        return dp[e][f];

    int mini = INT_MAX;

    for(int i = 1; i <= f; i++){

        int res = max(eggBreak(e - 1, i - 1, dp), eggBreak(e, f - i, dp));
        mini = min(res, mini);

    }

    return dp[e][f] = mini + 1;
}

int main(void){

    int e = 2;
    int f = 36;

    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));

    cout << eggBreak(e, f, dp) << endl;

    return 0;
}