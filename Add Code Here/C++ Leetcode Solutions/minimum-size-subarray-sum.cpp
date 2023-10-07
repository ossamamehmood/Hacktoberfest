class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,res = INT_MAX;
        int sumOfCurrentWindow = 0;
        for(int right = 0;right < nums.size();right++){
            sumOfCurrentWindow += nums[right];
            while(sumOfCurrentWindow >= target){
                res = min(res,right-left+1);
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
    }
};
