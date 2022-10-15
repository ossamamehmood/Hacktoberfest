#include<bits/stdc++.h>  
using namespace std; 

//find length of longest common subsequence
int lcs(string a,string b,int m,int n)  {   

    int dp[m + 1][n + 1];   
    for (int i = 0; i <= m; i++) {  
        for (int j = 0; j <= n; j++)  {  
            //dp[i][j] contains lcs of string a(0..i) and b(0..j)
            if (i == 0 || j == 0)  
                dp[i][j] = 0;  
            else if (a[i - 1] == b[j - 1])  
                dp[i][j] = dp[i - 1][j - 1] + 1;  
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
    return dp[m][n];  
}


int main() {  
    //desired strings are taken
    string a = "longest";
    string b = "longsequence";

    int m = a.size();  
    int n = b.size();  
    
    //Print the length of longest common subsequence  
    cout << "The length of Longest Common Subsequence is " << lcs(a,b,m,n);  
      
    return 0;  
}  