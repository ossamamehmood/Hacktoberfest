#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumBeautifulTowers(vector<int>& heights, vector<int>& maxHeights) {
    int n = heights.size();
    
    vector<int> dp_inc(n, 0);  
    vector<int> dp_dec(n, 0); 
    
    dp_inc[0] = dp_dec[n - 1] = heights[0];
    
    for (int i = 1; i < n; i++) {
        dp_inc[i] = min(dp_inc[i - 1] + 1, maxHeights[i]);
        dp_inc[i] = max(dp_inc[i], heights[i]);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        dp_dec[i] = min(dp_dec[i + 1] + 1, maxHeights[i]);
        dp_dec[i] = max(dp_dec[i], heights[i]);
    }
    
    int max_sum = heights[0];
    
    for (int i = 1; i < n; i++) {
        max_sum = max(max_sum, dp_inc[i - 1] + heights[i]);
        max_sum = max(max_sum, dp_dec[i] + heights[i]);
    }
    
    return max_sum;
}

int main() {
    vector<int> heights = {2, 1, 1, 5, 6, 2, 3};
    vector<int> maxHeights = {2, 2, 2, 2, 1, 2, 2};
    int result = maxSumBeautifulTowers(heights, maxHeights);
    cout << result << endl; 
    
    return 0;
}
