class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int ans=m[nums[n]];
        return ans;
        
        
    }
};