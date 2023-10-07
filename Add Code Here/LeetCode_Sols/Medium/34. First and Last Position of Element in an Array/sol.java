public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int[] searchRange(int[] nums, int target) {
            int[] arr = new int[2];
            arr[0] = firstIndex(nums, target);
            arr[1] = lastIndex(nums, target);
            return arr;
        }

        int firstIndex(int[] nums, int target) {
            int index = -1;
            int s = 0;
            int e = nums.length - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] >= target) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }

                if (nums[mid] == target) {
                    index = mid;
                }
            }
            return index;
        }

        int lastIndex(int[] nums, int target) {
            int index = -1;
            int s = 0;
            int e = nums.length - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] <= target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }

                if (nums[mid] == target) {
                    index = mid;
                }
            }
            return index;
        }
    }
}