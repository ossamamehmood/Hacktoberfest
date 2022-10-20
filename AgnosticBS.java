package BinarySearch;

import java.util.Scanner;

public class AgnosticBS {


    public  static int agnosticSearch(int [] nums, int target){
        int start = 0;
        int end = nums.length - 1;
        boolean isAsc = nums[start] < nums[end];
        System.out.println(isAsc);
        while (start <= end){
            int mid = start + (end - start) / 2;
            if(target == nums[mid]){
                return mid;
            }
            if(isAsc == true){
                if(target > nums[mid]){
                    start = mid + 1;
                }else if (target < nums[mid]){
                    end = mid - 1;
                }else {
                    return  mid;
                }
            }else {
                if(target > nums[mid]){
                    end = mid - 1;
                }else if (target < nums[mid]){
                    start = mid + 1;
                }else {
                    return  mid;
                }

            }
        }
        return  -1;

    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] nums = {100,40,17,9,8,7,7,5,4,1};
        int target = input.nextInt();
        System.out.println("\n Location found: "+ agnosticSearch(nums, target));

    }
}
