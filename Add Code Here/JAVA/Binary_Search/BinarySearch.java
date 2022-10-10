public class BinarySearch {

    private static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9};
        int target = 7;
        System.out.println(binarySearch(arr, target));
    }

    private void binarySearch(arr, target) {
        int start = 0;
        int end = arr.length - 1;
        int mid = start + (end - start)/2;
        while (start <= end) {    
            if (target == arr[mid]) {
                return mid;
            }
            else if (target > arr[mid]) {
                start = mid + 1;
            }
            else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}