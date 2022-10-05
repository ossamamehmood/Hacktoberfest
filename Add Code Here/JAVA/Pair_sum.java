/*  Pair Sum/ two sum : finding all the pairs whose sum is x 
(For ex: finding all the pairs whose sum is 7)

            Naive solution--brute force approach
                                                        */
import java.util.*;
public class Pair_sum {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number whose pairs are to be found: ");
        int sum=sc.nextInt();
        int[] arr={2,3,4,5,1};
        pairSum(arr,sum); 

    }

    public static void pairSum(int[] arr, int sum){
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]+arr[j]==sum){
                    System.out.println(arr[i]+" "+arr[j]);
                }

            }
        }
    }
}
