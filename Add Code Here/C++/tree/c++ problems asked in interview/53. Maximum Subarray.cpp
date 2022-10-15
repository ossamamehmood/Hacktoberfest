Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
  
Solution :
Time Complexity - O(n) where n is the size of the array

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], max_sum = nums[0];
        for(int i =1;i<nums.size();i++)
        {
            sum = max(nums[i],sum+nums[i]);
            max_sum = max(sum,max_sum);
        }
        return max_sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m1= INT_MIN;
        int m2 = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            m2 = max(nums[i],m2+nums[i]);
            if(m2>m1)
                m1=m2;
            
            if(m2<0)
                m2=0;
        }
        return m1;
    }
};
