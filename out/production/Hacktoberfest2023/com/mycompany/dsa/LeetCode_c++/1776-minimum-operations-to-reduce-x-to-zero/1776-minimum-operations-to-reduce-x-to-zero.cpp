class Solution {
public:
    // int solve( vector<int>&nums ,int x ,int i ,int j,int step)
    // {
    //     if(x==0)
    //     {
    //         return step;
    //     }
    //     if(x<0 || j<0 || i>=nums.size())
    //      return INT_MAX;

    //     int left = solve(nums,x-nums[i],i+1,j,step+1);
    //     int right = solve(nums,x-nums[j],i,j-1,step+1);

    //     return min( left,right ) ;

    // }

    int minOperations(vector<int>& nums, int x) 
    {
        // int i=0;
        // int j=nums.size()-1;

        //  int sum=0;
        // for(auto it :nums)
        //  sum+=it;
        //  if(sum<x)
        //   return -1;
        // int ans= solve(nums,x,i,j,0);
        // return ans==INT_MAX ? -1:ans;

        int sum =0;
        for( auto it:nums )
         sum+=it;
        sum -=x;
        
        int left =0,right=0;
        int temp=0;
        int n = nums.size();
        int res =0;
        
        if(sum==0)
         return n;

        while(  right<n)
        {
          temp+=nums[right];

          while(temp>sum && left<n)
              temp-=nums[left++];
          
          if( temp == sum )
              res=max(res,right-left+1);
          
          right++;
        }
        return res ? n-res:-1;

    }
};