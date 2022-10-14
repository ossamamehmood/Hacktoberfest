class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>>v;
        int k=nums[0];
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || k!=nums[i])
            {
                cout<<i<<" "<<k<<" ";
                k=nums[i];
                cout<<k<<endl;
                int l=i+1, h = n-1;
                while(l<h)
                {
                    if(nums[l]+nums[h]==-k)
                    {
                        v.push_back({k,nums[l],nums[h]});
                        while(l<h && nums[l]==nums[l+1]) l++;
                        while(l<h && nums[h]==nums[h-1]) h--;
                        l++;
                        h--;
                    }
                    else if(nums[l]+nums[h]>-k)
                        h--;
                    else l++;
                }
            }
        }
        return v;
    }
};
