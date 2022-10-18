class Solution {
    public void moveZeroes(int[] nums) {
        int temp=0, left=0, right=0;
        if(nums.length==0 || nums.length==1) return;
        for(int i=0; i<nums.length; ++i){

        if(nums[right]==0){
            ++right;
        }
            
        else {
            temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            ++right;
            ++left;
        }
    }
}}
