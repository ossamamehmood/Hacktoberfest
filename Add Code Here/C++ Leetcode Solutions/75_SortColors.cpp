class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,m=0,e=nums.size()-1;

        while(m<=e){
           if(nums[m]==2){
               swap(nums[m],nums[e]);
               e--;
           }
           else if(nums[m]==0)
           {
               swap(nums[s],nums[m]);
               s++,m++;
           }
           else
            m++;
        }
    }
};
