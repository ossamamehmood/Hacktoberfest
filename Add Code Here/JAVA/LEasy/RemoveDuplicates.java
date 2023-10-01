package LEasy;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class RemoveDuplicates {
    public static void main(String[] args) {

        int[] arr={1,1,2,2,2,3,3};


//        bruteforce(arr);
        optimal(arr);




    }

    private static void optimal(int[] arr) {

        int i=0;
        for (int j = 1; j <arr.length ; j++) {
            if(arr[i]!=arr[j]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        System.out.println(i+1);

    }

    private static void bruteforce(int[] arr) {
        Set<Integer> s=new HashSet<>();
        for (int i = 0; i <arr.length ; i++) {
            s.add(arr[i]);
        }

        int idx = 0;
        for (int value : s) {
            arr[idx] = value;
            idx++;
        }
        for (int i = idx; i < arr.length; i++) {
            arr[i]=0;
            
        }

        System.out.println(Arrays.toString(arr));

    }
}
