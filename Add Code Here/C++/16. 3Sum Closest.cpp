class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans=0;
        int mindis=INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            
            int a=i+1, b = n-1;
            
            while(a<b){
                
                int sum = nums[i]+ nums[a]+ nums[b];
                
                if(abs(sum-target)<mindis)
                {
                    mindis=abs(sum-target);
                        ans= sum;
                }
                if(sum==target)
                    return sum;
                
                if(sum>target)
                    b--;
                else
                    a++;
                
                
                
            }
            
            
        }
        
        
        
        
        
        
        
        
        return ans;
        
        
        
        
        
        
    }
};
