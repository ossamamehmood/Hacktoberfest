//que is check string x is a subsequence of string y return true or false

#include <bits/stdc++.h>
using namespace std;

int lcs(string &x, string &y,int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];

}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n=x.length();
    int m=y.length();
// just check lcs length is equal to string x length if yes return true else false 
    if(lcs(x,y,n,m)== n){
        cout<<"true";
    }
    else 
    cout<<"false";

}

