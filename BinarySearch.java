//Binary Search using function
/*
Binary Search used for Searching elements in sorted arrays.
 */
import java.util.Scanner;
public class BinarySearch {
    static int Search(int[] nums, int target){
        int start = 0; //start index
        int end = nums.length-1;//ending element index
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target < nums[mid])
                end = mid -1;
            else if(target > nums[mid])
                start = mid + 1;
            else
                return mid;
        }
        return -1;
    }// end of BinarySearch Function
    //main
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int target = s.nextInt();
        s.close();
        int[] nums = {-23, -21, -4, 0, 3, 43, 566, 343, 6345};
        int ans = Search(nums, target);
        System.out.println(ans);
    }
}
