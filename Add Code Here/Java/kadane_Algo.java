/**
 * kadane's_Algo
 * Find largest sum of the contiguous subarray of an array
 * Time complexity using Kadane algorithm- O(n)
 * contributed by code-with-Priyanshu
 */

import java.util.*;
public class kadane_Algo {

    public static void main(String[] args) {
        int[] arr={1,5,-2,8,-3,5};
        int n=6;
        int sum=0;
        int maxi=arr[0];
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=Math.max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        System.out.println("The maximum sum of contiguous subarray is "+maxi);
    }    
}