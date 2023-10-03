#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void helper(int idx,vector<int>nums,vector<int>& output,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(output);
            return;
        }
        helper(idx+1,nums,output,ans);
        output.push_back(nums[idx]);
        helper(idx+1,nums,output,ans);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        helper(0,nums,output,ans);
        return ans;
    }
};