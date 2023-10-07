//2869. Minimum Operations to Collect Elements

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
       
        int c=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<=k)
            {
                s.insert(nums[i]);
            }
           c++;
             if(s.size()==k)
               return c;
        }
        return 0;
    }
};