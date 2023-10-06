// Question 2 from Leetcode Weekly Contest 363
// Question ID: 2860

class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) ans++;
        for(int i=0; i<n-1; i++){
            if(i>=nums[i] && i+1<nums[i+1]) ans++;
        }
        if(n-1>=nums[n-1]) ans++;
        return ans;
        
    }
};