#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1, n = prices.size();
        int ans = 0;
        while (i < n && j < n) {
            int diff = prices[j] - prices[i];
            if (diff >= 0) {
                ans = max(ans, diff);
            } else {
                i = j;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices;

    // Input stock prices into the vector
    int price;
    cout << "Enter stock prices (enter a negative number to stop): ";
    while (true) {
        cin >> price;
        if (price < 0) break;
        prices.push_back(price);
    }

    int maxProfit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
