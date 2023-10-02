class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m; 
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int t=target-nums[i]; 
            if(m.find(t)!=m.end()) 
            {
                ans.push_back(m[t]);
                ans.push_back(i);
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
