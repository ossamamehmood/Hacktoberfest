class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minSofar = prices[0];
        
        for(int i=0; i<n; i++){
            minSofar = min(minSofar, prices[i]);
            int profit = prices[i]-minSofar;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};