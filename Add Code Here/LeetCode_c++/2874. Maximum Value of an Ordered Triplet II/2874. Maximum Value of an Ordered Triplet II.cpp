class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return 0;
        }
        if (len == 3) {
            long long temp = (long long)(nums[0] - nums[1]) * nums[2];
            return max(0LL, temp);
        }

        long long prefixMax[len];
        prefixMax[0] = nums[0];

        for (int i = 1; i < len; i++) {
            prefixMax[i] = max(prefixMax[i - 1], (long long)nums[i]);
        }

        long long suffixMax[len];
        suffixMax[len - 1] = nums[len - 1];

        for (int i = len - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], (long long)nums[i]);
        }

        long long result = 0;

        for (int i = 1; i < len - 1; i++) {
            long long temp = (prefixMax[i - 1] - (long long)nums[i]) * suffixMax[i + 1];
            result = max(result, temp);
        }

        return result;
    }
};


// Hint: calculate prefix and suffix maximums and then iterates through the array to calculate the maximum triplet

// Time Complexity: O(n), where n is the length of the array
