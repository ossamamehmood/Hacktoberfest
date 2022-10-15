class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==0) return 1;
            else if(nums[0] == 1) return 2;
            else return 1;
        }
        for(int i = 0;i<n;i++){
            if(nums[i]<=0) nums[i] = n+1;
        }
        int ans = n+1;
        for(int i = 0;i<n;i++){
            if(abs(nums[i])>n) continue;
            else nums[abs(nums[i])-1] = abs(nums[abs(nums[i])-1])*(-1);
        }
        
        for(int i = 0;i<n;i++){
            if(nums[i]>0) {
                ans = i+1;
                break;
            }
        }
        return ans;
        
        
    }
};
