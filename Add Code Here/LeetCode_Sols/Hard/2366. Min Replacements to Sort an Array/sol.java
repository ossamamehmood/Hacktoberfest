public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    public class Solution {
        public long minimumReplacement(int[] nums) {
            long operations = 0;
            long prev_bound = nums[nums.length - 1];

            for (int i = nums.length - 2; i >= 0; i--) {
                long num = nums[i];
                long no_of_times = (num + prev_bound - 1) / prev_bound;
                operations += no_of_times - 1;
                prev_bound = num / no_of_times;
            }

            return operations;
        }
    }
}