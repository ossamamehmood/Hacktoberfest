Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

Solution(using two pointer technique):

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        
        if(nums.size()<3) //if size of the vector is smaller than 3
            return res;
        
        sort(nums.begin(), nums.end()); //sorting the vector to use the two pointer technique
        
        int i = 0, n = nums.size();
        // in two pointer technique the pointer will go from 0 to maxium n-3 because it has to find a triplet with the sum equal to 0
        
        while(i<(n-2))
        {
            int j = i+1, k = n-1 , target = (-1)*nums[i]; //two pointer j and k and target is made negative so as to negate the sum 
            while(j<k)
            {
                int s = nums[j]+nums[k];
                if(s<target)
                    j++;
                else if(s>target)
                    k--;
                else{
                    vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                res.push_back(temp);
                
                j++;
                k--;
                
                while(j<k && nums[j]==nums[j-1])j++;
                while(k>j && nums[k]==nums[k+1])k--; 
                }
                    
            }
            i++;
        while(i<nums.size() && nums[i]==nums[i-1])i++;
        }
        
        return res;
    }
};
