class Solution {
    public int[] buildArray(int[] nums) {
        int len = nums.length, i = 0;
        int[] newNums = new int[len];
        
        for(int num: nums){
            newNums[i++] = nums[num];
        }
        
        return newNums;
    }
}
