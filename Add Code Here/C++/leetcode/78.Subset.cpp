#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<vector<int>>ans;
    void helper(int idx,vector<int>&nums,vector<int>& output){
        if(idx==nums.size()){
            ans.push_back(output);
            return;
        }
        helper(idx+1,nums,output);
        output.push_back(nums[idx]);
        helper(idx+1,nums,output);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        helper(0,nums,output);
        return ans;
    }
};
