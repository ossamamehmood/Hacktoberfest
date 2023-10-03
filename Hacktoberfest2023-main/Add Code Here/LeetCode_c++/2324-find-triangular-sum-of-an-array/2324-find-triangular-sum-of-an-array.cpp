class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        if(nums.size()==1)
         return nums[0];

        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for( int j=0;j<n;j++)
            {
                if(j==n-1-i)
                {
                    nums[j]=0;
                    break;
                }
                else
                 nums[j]=( nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};