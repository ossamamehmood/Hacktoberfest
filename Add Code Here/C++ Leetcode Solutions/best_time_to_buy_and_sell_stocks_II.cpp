class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]> prices[i-1]){
                profit+= prices[i]- prices[i-1];
            }
        }
        return profit;
    }
};

//optimised approach to solve the leetcode question
// Leetcode Question : 122. Best Time to Buy and Sell Stock II
//Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150 