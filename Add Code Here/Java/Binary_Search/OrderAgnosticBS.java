package Java.Youtube.Binary_Search;

public class OrderAgnosticBS {
    public static void main(String[] args) {
        int[] arr1 = {-13, -2, 0, 1, 3, 13, 23, 25, 45, 69};
        int[] arr2 = {434, 432, 353, 133, 93, 80, 69, 34, 24, 12, 3, 1};
        int target1 = 13;
        int target2 = 69;
        int ans1 = orderAgnosticBS(arr1, target1);
        int ans2 = orderAgnosticBS(arr2, target2);

        System.out.println(ans1);
        System.out.println(ans2);
    }


    // for ascending or descending both
    static int orderAgnosticBS (int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        boolean isAsc;   // boolean isAsc = arr[start] < arr[end];
        if (arr[start] < arr[end]){
            isAsc = true;
        }else {
            isAsc = false;
        }
        while (start <= end) {
            // find the middle element
//           int mid = (start + end) / 2 ; // might be possible that (start + end) execeeds the range of int in java
            int mid  = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (isAsc){
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }else {
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
//            if (target < arr[mid]) {
//                end = mid - 1;
//            } else if (target > arr[mid]) {
//                start = mid + 1;
//            }else {
//                // ans found
//                return mid;
//            }
        }

        return -1;

    }
}
