Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Solution : 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>res ; 
        vector<int> result;
        
        for(int i=0;i<nums.size();i++){
            if(res.find(target-nums[i])!=res.end())
            {
                result.push_back(i);
                result.push_back(res[target-nums[i]]);
                break;
            }
            else
                res[nums[i]]=i;
        }
        return result;
    }
};

Time Complexity : O(n)

 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int diff = target-nums[i];
            if(m.count(diff))
                return {m[diff],i};
            else
                m[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};
