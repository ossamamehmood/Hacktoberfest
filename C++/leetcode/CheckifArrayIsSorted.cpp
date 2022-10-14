class Solution {
public:
    
    bool check(vector<int>& nums) {
        int n = nums.size()-1;
        
        int count = 0;                         // Store a count with 0
        
        if(nums[n]>nums[0]){
           count++;                   
        }
        
        for(int i = 1;i<=n;i++){
            
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        
        if(count<=1){                          // if the count is more than 1 that means there are more than 2 values which is greater than there previous value in that case the array is not  sorted and rotated
            return true;
        }
        
        return false;
        
    }
};
