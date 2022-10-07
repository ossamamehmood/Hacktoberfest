class Solution {
public:
   int binarysearch(vector<int> nums, int target, int low, int high)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int pivotindex(vector<int> nums)
    {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int prev=mid-1;
            int next=mid+1;
            if(mid==0){
            prev=(mid+n-1)%n;
            }
            if(mid==n-1){
            next=(mid+1)%n;
            }
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]) return mid;
            else if(nums[mid]>=nums[0]) low=mid+1;
            else if(nums[mid]<=nums[n-1]) high=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        if(nums[0]<nums[n-1]) //This is important to check otherwise it will not pass few test cases
        {
            return binarysearch(nums,target,0,n-1);
        }
        
        int index=pivotindex(nums);
        int a=binarysearch(nums,target,0,index-1);
        int b=binarysearch(nums,target,index,n-1);
        
        
        if(a>=0) return a;
        else if(b>=0) return b;
        return -1;
    }
};