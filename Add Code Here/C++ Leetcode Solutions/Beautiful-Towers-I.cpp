// Question 2 from Leetcode Weekly Contest 364
// Question ID: 2865

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
       
        for(int i=0; i<n; i++){
            long long sum=0;
            int pre = INT_MAX;
            for(int j=i; j>=0;j--){
                pre = min(nums[j],pre);
                sum+=pre;
            }
            pre = INT_MAX;
            for(int j=i+1; j<n; j++){
                pre = min(nums[j],pre);
                sum+=pre;              
            }
            ans = max(ans,sum);
        }
        return ans;
        
    }
};