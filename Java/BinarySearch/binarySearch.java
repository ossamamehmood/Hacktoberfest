package com.BinarySearch;

public class binarySearch {

    public static void main(String[] args) {
        int[] arr = {11,23,45,67,78,89,90};
        int target = 7;
        System.out.println(floor(arr,target));
    }



    //CEILING AND FLOOR
    static int floor(int[] arr, int target)
    {

//        boolean isAsc = arr[0] < arr[arr.length-1];
        int s = 0;
        int e = arr.length -1 ;
        while(s <= e)
        {

            if(target < arr[0]){
                return -1;
            }
            int mid = s + (e-s)/2;
            if(target == arr[mid])
            {
                return mid;
            }
//            if (isAsc){
                else if(target > arr[mid])
                {
                    s = mid+1;
                }

                else {
                    e = mid-1;
                }
//            }

//            else {
//                if(target < arr[mid])
//                {
//                    s = mid+1;
//                }
//
//                else if(target > arr[mid]){
//                    e = mid-1;
//                }
//            }
        }
        //        flooring
        return arr[e];

    }
}

