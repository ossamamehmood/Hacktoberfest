int subset(vector<int> &A, int B,int n,vector<vector<int>>&dp){
    if (B==0){
        return 1;
    }
    if (n==0){
        return 0;
    }
    if (dp[n][B]!=-1){
        return dp[n][B];
    }
    if (A[n-1]<=B){
        dp[n][B]=subset(A,B-A[n-1],n-1,dp)||subset(A,B,n-1,dp);
    }
    else {
        dp[n][B]=subset(A,B,n-1,dp);
    }
    return dp[n][B];
}
int Solution::solve (vector<int> &A, int B) {
    int n=A.size(),i,j;
    vector<vector<int>>dp(n+1);
    for (i=0;i<n+1;i++){
        for(j=0;j<B+1;j++){
            dp[i].push_back(-1);
        }
    }
    return subset(A,B,n,dp);
}
