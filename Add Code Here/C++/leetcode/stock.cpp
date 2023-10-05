class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0]; // Initialize the minimum price to the first element
        int maxprofit = 0;    // Initialize the maximum profit to 0
        int n = prices.size(); // Get the number of days for which prices are available
        
        // Loop through the prices starting from the second day (index 1)
        for(int i = 1; i < n; i++) {
            // Calculate the profit (difference between the current price and the minimum price seen so far)
            int cost = prices[i] - mini;
            maxprofit = max(cost, maxprofit);

            mini = min(mini, prices[i]);
        }
        
        // Return the maximum profit achievable
        return maxprofit;
    }
};
