package com.BinarySearch;

public class element_in_infinite_array {
    public static void main(String[] args) {
        //doubling the size of array everytime and apply binary search;

        int[] arr = {12,34,55,56,57,59,67,89,90,123};
        int target = 67;
        System.out.println(ans(arr,target));
    }

    static int ans(int[] arr , int target){

        int s = 0;
        int e = 1;
        while(target > arr[e]){
            int newStart = e + 1;
            e = e + (e-s+1);
            s = newStart;
        }

        return binarySearch(arr, target, s, e);
    }

    static int binarySearch(int[] arr, int target, int s, int e) {
        int mid = s + (e - s) / 2;
        while (s <= e){

            if(target < arr[mid]){
                e = mid - 1;
            }
            else if(target > arr[mid]){
                s = mid + 1;
            }
            else {
                return mid;
            }
    }


        return -1;
    }

}
