lass Solution {
public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
        //base case
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;
        //here we'll check whether we can buy it or not and when we can sell it
        if(buy){  //means if buy is 1
            profit = max(-prices[ind]+func(ind+1,0,prices,dp),0+func(ind+1,1,prices,dp));
        }
        else{
            profit = max(prices[ind]+func(ind+1,1,prices,dp),0+func(ind+1,0,prices,dp));
        }
        return  dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        //we write a very good recursion concept here
        int buy=1;
        //memoization
        int n = prices.size();

        //for tabulation write base cases

        //now for space optimization
        vector<int> dp(2,0);
        for(int ind=n-1;ind>=0;ind--){
            vector<int> curr(2,0);
            for(int buy=0;buy<2;buy++){
                 int profit=0;
        //here we'll check whether we can buy it or not and when we can sell it
                if(buy){  //means if buy is 1
                    int case1 = -prices[ind];
                    int case2 = 0;
                    if(ind+1<n){
                        case1 += dp[0];
                        case2 = dp[1];
                    }
                    profit = max(case1,case2);
                }
                else{
                    int case1 = prices[ind];
                    int case2 = 0;
                    if(ind+1<n){
                        case1 += dp[1];
                        case2 = dp[0];
                    }
                    profit = max(case1,case2);
                }
                curr[buy] = profit;
            }
            dp=curr;
        }

        return dp[buy];
    }
};
