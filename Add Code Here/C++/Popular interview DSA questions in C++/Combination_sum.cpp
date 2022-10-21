// leetcode link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void printSum(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &res, int target, int n) {
        if (ind == n) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }
        
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            printSum(ind, arr, ds, res, target-arr[ind], n);
            ds.pop_back();   
        }
        printSum(ind+1, arr, ds, res, target, n);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> res;
        printSum(0, candidates, ds, res, target, n);
        return res;
    }
};