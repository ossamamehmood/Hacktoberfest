Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
  
 Solution:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool>present(n);
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0 && nums[i]<=n)
                present[nums[i]]=true;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(present[i]!=true)
                return i;
        }
        return n+1;
    }
};

Time Complexity : O(n) 
Space Complexity : O(n)
 
