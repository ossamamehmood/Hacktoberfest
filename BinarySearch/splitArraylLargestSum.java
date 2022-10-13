package com.BinarySearch;

public class splitArraylLargestSum {
    public static void main(String[] args) {

    }

    public int splitArray(int[] nums, int m) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.length; i++) {
            start = Math.max(start, nums[i]);
            end += nums[i];
        }
        //binary search
        while(start < end){
            int mid = start + (end - start)/2;
            int sum = 0;
            int pieces = 1;
            for(int i : nums){
                if(sum + i > mid){
                    sum = i;    //adding into the new piece (sum will start from current number
                    pieces++;  //creating new piece;
                }
                else{
                    sum+=i;
                }
            }

            if(pieces <= m){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start; //or end s=e=m
    }
}
