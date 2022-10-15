#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(int n, int t, vector<int> points, vector<int> time, vector<vector<int>> &dp){
    if(n==0){
        if(t>=time[n])
            return points[n];
        return 0;
    }
    if(dp[n][t]!=-1)
        return dp[n][t];
    int take=INT_MIN;
    int nottake=0;
    nottake=0+helper(n-1,t,points,time,dp);
    if(t>=time[n])
        take=points[n]+helper(n-1,t-time[n],points,time,dp);
    return dp[n][t]=max(nottake,take);
}
int sol(int input1, int input2, vector<int> input3, vector<int> input4){
    vector<vector<int>> dp(input1,vector<int> (input2+1,-1));
    return helper(input1-1, input2, input3, input4, dp);
}
int main(){
    cout<<sol(3,7,{2,6,9},{3,5,3});
    return -1;
}
