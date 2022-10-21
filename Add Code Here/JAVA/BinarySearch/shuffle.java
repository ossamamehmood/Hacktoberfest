package com.BinarySearch;

import java.util.Arrays;

public class shuffle {
    public static void main(String[] args) {
        int[] arr = {2,5,1,3,4,7};

        System.out.println(Arrays.toString(shuffle1(arr, 3)));
    }


    public static int[] shuffle1(int[] nums, int n) {


        int[] arr = new int[2*n];
        int i =0;
        int x = 0;
        int y = n;
        while(x < n){
            arr[i] = nums[x];
            i++;
            x++;
            arr[i] = nums[y];
            i++;
            y++;
        }
        return arr;

    }
}
