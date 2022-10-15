Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
  
Solution :

Time Complexity - O(1) because we are just comparing the size of the array and the hashmap(hashmap does not store duplicate values) 
Space Complexity - O(n) , it is being used to stoe the array in the hashmap which requires space. 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return (nums.size() > unordered_set<int>(nums.begin(), nums.end()).size());     
    }
};

Time Comlexity - O(n) where n is the number of elements in the array.
Space Complexity - O(n) because I am using a hashmap to store the frequency of occurence of each element. 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
        }
        
        for(auto x:ans)
        {
            if(x.second>=2)
            {
                return true;
                break;
            }
        }
        return false;
    }
};
