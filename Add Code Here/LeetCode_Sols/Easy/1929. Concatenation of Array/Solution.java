class Solution {
    public int[] getConcatenation(int[] nums) {
        int len = nums.length;
        int[] newNums = new int[2 * len];
        
        System.arraycopy(nums, 0, newNums, 0, len);
        System.arraycopy(nums, 0, newNums, len, len);
        
        return newNums;
    }
}
