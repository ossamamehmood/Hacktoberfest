class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        vector <int> v;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum<target)
                i++;
            else if(sum>target)
                j--;
            else
            {
                v.push_back(m[nums[i]]);
                v.push_back(m[nums[j]]);
                return v;
            }
        }
        return v;
    }
};
