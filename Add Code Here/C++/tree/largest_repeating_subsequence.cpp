#include <bits/stdc++.h>
using namespace std;

int longRepSubseq(string a){
    int n = a.length();
 
    //initialize DP table
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            // Characters match but indexes are not same
            if (a[i-1] == a[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];          
            //characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main(){
    string a = "aabbcdee";
    cout << "Length of Largest Repeating Subsequence is "<< longRepSubseq(a);
    return 0;
}