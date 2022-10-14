package com.BinarySearch;
public class Solution {

    public static void main(String [] args){
        int var = 0;

        int[] nums = {1,2,3,4,5,6,7,8};
        System.out.println(nums[0]);
//        System.out.println(nums[1]);
        for (int i = 0; i <= nums.length; i++) {
            var = nums[i] + nums[i + 1];// 1,2 = 3; 3,3 = 6;
            nums[i] = var;
            nums[i+1] = nums[i];
            System.out.println(var);
        }

    }
}
