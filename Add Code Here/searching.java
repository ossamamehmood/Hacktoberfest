#####BINARY-SEARCH

/* import java.util.*;


public static void main(string[] args) {
    int[] arr= {22, 33, 44, 55, 66, 77};    
    int target= 22;
    int ans= binarySearch(arr, target);
    System.out.println(ans);


static int binarySearch(int[] arr, int target) {
    int start = 0;
    int end = arr.length - 1;
    int mid= start + (end - start) / 2;

    while(start<=end) {
        if(target < arr[mid]){ 
            end = mid - 1;

        }

        else if(target<arr[mid]) {
            start = mid + 1;
        }

        else{
            return mid;
        }
    

    }
    return -1;
}
}

 */

  ####AGNOSTIC-BINARY SEARCH

   import java.util.*;

 public static void main(string[] args) {
    int[] arr= {22, 33, 44, 55, 66, 77};    
    int target= 22;
    int ans= binarySearch(arr, target);
    System.out.println(ans);



 static int binarySearch(int[] arr, int target) {
    int start=0;
    int end= arr.length-1;

    //find if array is ascending or descending

    boolean isAsc;
    if(arr[start] > arr[end]) {
        return true;
    } else{
        return false;
    }

    int mid= start + (end - start) / 2;


    

    while(start<=end) {
        if(target < arr[mid]){ 
            end = mid - 1;

        }

        else if(target<arr[mid]) {
            start = mid + 1;
        }

        else{
            return mid;
        }
    }
      return -1;
} 
 
 }
