public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int findMin(int[] nums) {
            int start = 0, end = nums.length - 1, ans = start;
            while (nums[start] > nums[end]) {
                int mid = (start + end) / 2;
                if (nums[mid] <= nums[start] && nums[mid] <= nums[end]) {
                    end = mid;
                } else if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
                    start = mid + 1;
                } else {
                    return nums[mid];
                }
                ans = start;
            }
            return nums[ans];
        }
    }
}
