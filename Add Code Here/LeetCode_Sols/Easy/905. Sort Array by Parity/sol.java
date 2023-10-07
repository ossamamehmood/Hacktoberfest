public class sol{
    public static void main(String[] args) {
        // call your fn here
    }
}
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int left = 0, right = 0;
        int n = nums.length;
        
        while (right < n) {
            if (nums[right] % 2 == 0) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
            }
            right++;
        }
        return nums;
    }
}