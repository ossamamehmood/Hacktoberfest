class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    long long value = (static_cast<long long>(nums[i]) - nums[j]) * nums[k];
                    maxVal = max(maxVal, value);
                }
            }
        }
        return maxVal;
    }
};

// brute-force approach by iterating through all possible triplets of indices (i, j, k) and calculating the value for each triplet
// Time Complexity: O(n^3)
