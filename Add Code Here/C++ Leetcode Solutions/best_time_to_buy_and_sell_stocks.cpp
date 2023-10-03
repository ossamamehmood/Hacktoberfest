class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minPrice = INT_MAX;
        int profit=0;
        int ans=0;
        for(int i=0;i<n;i++){
             minPrice = min(minPrice, prices[i]);
            profit= abs(prices[i]-minPrice);
            ans = max(ans, profit);
        }
        return ans;
    }
};

// Leetcode question : 121. Best Time to Buy and Sell Stock
//Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150 