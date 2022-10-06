//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

public class Min_Num_Rotated_duplicate {
    public static void main(String[] args) {
        int[] arr1 = {4,5,6,7,0,1,2};
        int[] arr2 = {4,4,4,5,6,7,0,1,4};
        int[] arr3 = {3,3,3,3,3,3,3,3,1,3};
        int[] arr4 = {1,2,3,4,5,6};
        System.out.println(min_rotated(arr1));
        System.out.println(min_rotated(arr2));
        System.out.println(min_rotated(arr3));
    }
    static int min_rotated(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end--;
            }
        }
        return nums[start];
    }
}
