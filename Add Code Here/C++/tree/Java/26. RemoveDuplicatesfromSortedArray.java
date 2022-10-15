class Solution {  
    public int removeDuplicates(int[] nums) {
        int len=nums.length;
        int k=0;
        
        for(int i=1;i<nums.length;i++){
            if(nums[k]==nums[i]){
                len--;
            }else{
                nums[k+1]=nums[i];
                k++;
            }
        }
        
        return len;
    }
}
