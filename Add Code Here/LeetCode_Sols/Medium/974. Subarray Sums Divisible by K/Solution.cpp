class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum % k == 0) count++;
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(map[rem]) count += map[rem];
            map[rem] = map[rem] + 1;
        }
        return count;
    }
};
