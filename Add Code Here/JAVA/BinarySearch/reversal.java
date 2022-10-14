package com.BinarySearch;

import java.util.*;

public class reversal {

    static int reverse(Integer n[]){

        Collections.reverse(Arrays.asList(n));
        System.out.println(Arrays.asList(n));
        return 0;
    }
    public static void main(String[] args) {
        Integer[] arr = {2, 4, 7, 8, 5};
        reverse(arr);
    }
}
