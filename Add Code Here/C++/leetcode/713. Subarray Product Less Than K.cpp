class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0,end=0, noOfSubArray=0,prod=1;
        for(;end<n;end++){
            prod*=nums[end];
            while(prod>=k  && end>=start){
                prod/=nums[start++];
            }    
            noOfSubArray+=end-start+1;
        }
        return noOfSubArray;
    }
};


