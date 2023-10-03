class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // int low =1;
        // int high=nums.size()-1,cnt;

        // while( low<=high )
        // {
        //     int mid= low +(high-low)/2;
        //     cnt=0;
        //     for( int n:nums)
        //     if(n<=mid) cnt++;

        //     if(cnt<=mid)
        //      low =mid+1;
        //     else 
        //      high= mid-1; 
        // }
        // return low;

        for( int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i])-1;
            nums[index]*=-1;

            if(nums[index] >0)
             return  abs(nums[i]);
        }
        return -1;
    }
};