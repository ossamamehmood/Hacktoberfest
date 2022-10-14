package com.BinarySearch;

import java.util.Arrays;

public class searchIn2D {
    public static void main(String[] args) {
        int[][] arr = {
                {23 ,34 ,343, 34, 78},
                {38, 39, 93 ,87},
                {4, 6, 8},
                {99}
        };
        int target = 99;
        int[] ans = search(arr,target);
        System.out.println(Arrays.toString(ans));

    }
    static int[] search(int[][] arr, int target) {

        for (int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++){
                if(arr[i][j] == target )
                {

                    return new int[] {i,j};
                }
            }
        }
        return new int[] {-1,-1};
    }
}
