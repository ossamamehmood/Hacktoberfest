class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long sum=0;
        int n=nums.size();
        int rem=0;
        int pre=0;
        for(int i=0; i<n;i++){
            sum+=nums[i];
            rem=sum%k;
            if(s.count(rem))  return true;
            s.insert(pre);
            pre=sum%k;
        }
        return false;
    }
};
