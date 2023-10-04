//link: https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxTillNow = nums[0], maxProduct = nums[0], minTillNow = nums[0];
        for(int i = 1; i<n; i++){
            int temp = maxTillNow;
            maxTillNow = max({nums[i], nums[i]*maxTillNow, nums[i]*minTillNow});
            minTillNow = min({nums[i], temp*nums[i], nums[i]*minTillNow});
            maxProduct = max(maxTillNow, maxProduct);
        }
        return maxProduct;
    }
};
