package Java.Youtube.Binary_Search;

public class Main {
    public static void main(String[] args) {
//        int[] arr = {-13, -2, 0, 1, 3, 13, 23, 25, 45, 69};
        int[] arr = {434, 432, 353, 133, 93, 80, 69, 34, 24, 12, 3, 1};
        int target = 434;
//        if (arr[0] > arr[arr.length - 1]){
//
//        }
        int ans = binarySearch2(arr, target);
        System.out.println(ans);
    }


    // return index
    // return -1 if it does not exist


    // for ascending order
    static int binarySearch(int[] arr, int target) {

        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            // find the middle element
//           int mid = (start + end) / 2 ; // might be possible that (start + end) execeeds the range of int in java
          int mid  = start + (end - start) / 2;

          if (target < arr[mid]) {
              end = mid - 1;
          } else if (target > arr[mid]) {
              start = mid + 1;
          }else {
              return mid;
          }
        }
        return -1;
    }


    // for descending order
    static int binarySearch2(int[] arr, int target) {

        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            // find the middle element
//           int mid = (start + end) / 2 ; // might be possible that (start + end) execeeds the range of int in java
            int mid  = start + (end - start) / 2;

            if (target > arr[mid]) {
                end = mid - 1;
            } else if (target < arr[mid]) {
                start = mid + 1;
            }else {
                return mid;
            }
        }
        return -1;
    }
}
