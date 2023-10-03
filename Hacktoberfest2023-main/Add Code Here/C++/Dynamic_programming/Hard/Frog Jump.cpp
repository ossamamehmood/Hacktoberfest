//Link: https://leetcode.com/problems/frog-jump/description/

class Solution {
private:
    bool can(int ind, int prev_step, vector<int> &stones, vector<vector<int>> &dp) {
        if(ind == stones.size() - 1) return true;

        if(dp[ind][prev_step] != -1) return dp[ind][prev_step];

        int min_step = max(1, prev_step - 1);
        int max_step = prev_step + 1;

        int ind1 = lower_bound(stones.begin(), stones.end(), stones[ind] + min_step) - stones.begin();
        int ind2 = upper_bound(stones.begin(), stones.end(), stones[ind] + max_step) - stones.begin();

        bool res = false;
        for(int i = ind1; i < ind2; i++) {
            res = res || can(i, stones[i] - stones[ind], stones, dp);
        }
        return dp[ind][prev_step] = res;
    }

public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int> (stones.size(), -1));
        return can(0, 0, stones, dp);
    }
};
