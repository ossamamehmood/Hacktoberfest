class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        if(nums.size()<=2)
         return true;
        
        bool inc=true;
        bool dec=true;
        
        for(int i=0;i<nums.size()-1;i++)
        {
          if( !inc && !dec )
           return false;

          if( nums[i]>nums[i+1])
            inc = false;

          else if( nums[i]<nums[i+1])
            dec = false;  
        }
        return inc||dec;
        
    }
};