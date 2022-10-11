class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        unordered_map <int,int> mp;
        vector<int> res;
        
        
        for (int i=0; i<n; i++) {
            if (mp.find(nums[i])!=mp.end()) {
                res = {mp[nums[i]],i};
                return res;
            }
            else {
                mp[target-nums[i]] = i;
            }
        }
        return res;
    }
};
