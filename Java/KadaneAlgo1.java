
public class KadaneAlgo1 {
    public static void main(String[] args) {
        int nums[] = { 4, -1, 2, -7, 3, 4 };
        System.out.println("Maximum contiguous sum is " + kadanes(nums));
    }

    // Kadane's Algorithm O(n)
    static int kadanes(int[] nums) {
        // int maxSum = nums[0];
        // int currSum = 0;
        // for (int i = 0; i < nums.length; i++) {
        // // currSum = Math.max(currSum, 0); // if currSum is negative, reset it to 0
        // // currSum += nums[i];

        // currSum = currSum >= 0 ? currSum + nums[i] : nums[i];
        // maxSum = Math.max(maxSum, currSum);
        // }
        // return maxSum;

        int maxSum = nums[0];
        int currSum = 0;
        for (int i = 0; i < nums.length; i++) {
            currSum += nums[i];

            if (currSum > maxSum) {
                maxSum = currSum;
            }
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
}
