package Java.Leetcode;

//      Q : 977. Squares of a Sorted Array

import java.util.Arrays;

public class SquaresSortedArray {
    public int[] sortedSquares(int[] nums) {
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = nums[i] * nums[i];
        }
        Arrays.sort(arr);
        return arr;
    }
}
