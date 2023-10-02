package LEasy;

import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {
    public static void main(String[] args) {

        int[] arr={2,6,5,8,11};
//        System.out.println(bruteforce(arr,14));

//        System.out.println(better(arr,14));

//        Pair p=better(arr,14);
//        System.out.println(p.a);
//        System.out.println(p.b);

        System.out.println(optimal(arr,14));




    }

    private static boolean optimal(int[] arr, int target) {


        int start=0;
        int end=arr.length-1;
        Arrays.sort(arr);   
        while (start<end)
        {
            int sum=arr[start]+arr[end];
            if(sum==target){
                return true;
            }else if(sum<target){
                start++;
            }else{
                end--;
            }

        }
        return false;


    }

    static class Pair {
        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    private static Pair better(int[] arr, int sum) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int a = arr[i];
            int more = sum - a;
            if (mp.containsKey(more)) {
                return new Pair(more, a); // Return the pair of elements
            }
            mp.put(a, i);
        }
        return null; // No such pair found
    }

    private static boolean bruteforce(int[] arr,int sum) {

        for (int i = 0; i < arr.length; i++) {
            for (int j = i+1; j < arr.length; j++) {

//                if(i==j){
//                    continue;
//                }
                if(arr[i]+arr[j]==sum){
                    return true;
                }

            }

        }
        return false;

    }
}
