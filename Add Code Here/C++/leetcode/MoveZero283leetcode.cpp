//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Note that you must do this in-place without making a copy of the array.

  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
            tmp.push_back(nums[i]);
            }
        }
    int n2=tmp.size();
    for(int i=0;i<n2;i++){
        nums[i]=tmp[i];
    }
    for( int i= n2;i<n;i++){
        nums[i]=0;
    }
    

    }
};
