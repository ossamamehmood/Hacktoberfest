class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int d=nums.size();
        int sum=(d*(d+1))/2;
        for(int i=0;i<d;i++){
            sum-=nums[i];
        }
        return sum;
    }
};
