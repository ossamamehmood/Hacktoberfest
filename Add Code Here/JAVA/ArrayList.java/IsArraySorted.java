package io.github.jithset;

public class IsArraySorted {
    public static int isSorted(int arr[], int n)
    {
       /// Your code here
       boolean flag = false;
       int out=1;
       for (int i =1; i<n; i++) {
           if (arr[i] != arr[i-1] && arr[i]> arr[i-1]) flag = true;
           
       }
       if (flag) {
           for (int i =1; i<n; i++) {
               if (arr[i] != arr[i-1] && arr[i]< arr[i-1]) out = 0;
           }
       } else {
           for (int i =1; i<n; i++) {
               if (arr[i] != arr[i-1] && arr[i]< arr[i-1]) out = 1;
               
           }
       }
           
      return out;
    }

    public static void main(String[] args) {
        // int[] arr = {5,1,2,3,4};
        // int[] arr = {1,2,3,4};
        int[] arr = {5,4,3,2,1};
        int n = arr.length;
        System.out.println(IsArraySorted.isSorted(arr, n));
    }
}
