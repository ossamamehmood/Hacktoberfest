class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int m = 2 * n;
        vector<int> ans(m);
        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
        }
        for(int i = 0; i < n; i++){
            ans[n + i] = nums[i];
        }
        return ans;
    }
};