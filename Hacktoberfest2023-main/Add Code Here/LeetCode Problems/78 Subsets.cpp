class Solution {
public:
    void rec(vector<vector<int>> &a, vector<int> &v, vector<int> nums, int l) {
        if(l == nums.size()) {
            a.push_back(v);
            return;
        }
        v.push_back(nums[l]);
        rec(a,v,nums,l+1);
        v.pop_back();
        rec(a,v,nums,l+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> a;
        vector<int> v;
        rec(a,v,nums,0);
        return a;
    }
};
