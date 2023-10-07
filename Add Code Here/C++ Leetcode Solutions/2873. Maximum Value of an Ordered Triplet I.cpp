//2873. Maximum Value of an Ordered Triplet I

//code

class Solution {
    private:
    
public:
    long long maximumTripletValue(vector<int>& nums) {
       long long ans=-1;
        for(long long i=0;i<nums.size()-2;i++)
        {
            for(long long j=i+1;j<nums.size()-1;j++)
            {
                for(long long k=j+1;k<nums.size();k++)
                {
                   long long d = (static_cast<long long>(nums[i]) - static_cast<long long>(nums[j])) *                                 static_cast<long long>(nums[k]);
                ans = max(d, ans);

                
                }
            }
        }
        if(ans<0)
        {
            return 0;
    }
        else
        {
            return ans;
        }
        
    }
};