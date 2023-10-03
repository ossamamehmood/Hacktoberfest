//Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        if(a.size() < b.size()) swap(a, b);
        int m = a.size();
        int n = b.size();
        vector <int> dp(m+1, 0);
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j=n-1; j>=0; j--){
                if(a[i] == b[j])    {
                    dp[j+1] = 1+dp[j];
                }   else {
                    dp[j+1] = 0;
                }
                ans = max(ans, dp[j+1]);
            }
        }
        return ans;
    }
};
