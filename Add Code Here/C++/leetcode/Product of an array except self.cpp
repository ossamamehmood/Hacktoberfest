Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int prod=1,n=nums.size();
        int z=0;
        for(int i=0;i<n;i++)
        {
          // storing the product of all elements except zeros
            if(nums[i]!=0)
            prod=prod*nums[i];
          // counting the number of zeros
            if(nums[i]==0)
                z++;
        }

        int prod1=1;
        for(int i=0;i<n;i++)
        {
            // claculating product of whole elements in the array
            prod1=prod1*nums[i];
        }

        for(int i=0;i<n;i++)
        {
          // checking cconditions
            if(nums[i]!=0)
            ans.push_back(prod1/nums[i]);
              //if count of zeros are greater than 1 means every element will be zero in answer vector
            else if(nums[i]==0&&z>1)
                ans.push_back(0);
              // if all elements are not zero
            else if(nums[i]==0&&z!=n)
                ans.push_back(prod);
        }
        return ans;
    }
};

// Time complexity O(n)
// space complexity O(1) vector used in code is to store answer only.
