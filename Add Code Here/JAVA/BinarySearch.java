import java.util.*;
public class BinarySearch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Taking length of array as input
        int n = in.nextInt();
        // Getting the target element
        int target = in.nextInt();
        // Forming an array. It should be a sorted array
        int[] arr = new int[n];
        for(int i = 0; i< n ; i++){
            arr[i] = in.nextInt();
        }
        int start = 0;
        int end = arr.length- 1;
        while(start<=end){
            // mid value is the average of start and mid
            int mid = start+(end-start)/2;
            // If target is greater than mid, then the element after mid is start
             if(target > arr[mid] ){
                start = mid+1;
                 // If target is less than mid, then the element before mid is end
            }else if(target < arr[mid]){
                 end = mid-1;
                 //Hooray!! We have found the element
            } else{
                System.out.println(mid);
                break;
            }
        }
