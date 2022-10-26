class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            for(int j=i+1;j<nums.size();j++){
                num=__gcd(num,nums[j]);
                if(num==k) count++;
            }
            if(nums[i]==k) count++;
        }
        return count;
    }
};