Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

-----------------------------

class Solution {
public:
    
    int dp[2501];
    
    int solve(int i,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];   
        int len=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                len=max(len,1+solve(j,nums));
            }
        }    
        return dp[i]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        // int len=0;
        // for(int i=0;i<nums.size();i++){
        //     len=max(len,solve(i,nums));
        // }
        // return len;
        
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>tmp.back()) tmp.push_back(nums[i]);
            else{
                int idx=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[idx]=nums[i];
            }
        }
        return tmp.size();
        
    }
};
