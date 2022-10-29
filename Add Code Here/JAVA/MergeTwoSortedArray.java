import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class mergeTwoSortedArr {
    public static void main(String[] args) {
        long[] arr1 = {1,3,5,7};
        long[] arr2 = {0,2,6,8,9};
        int n = arr1.length;
        int m = arr2.length;


        System.out.println(Arrays.toString(arr1));
        System.out.println(Arrays.toString(arr2));

        ArrayList<Long> temp = new ArrayList<>();
        for(long i : arr1){
            temp.add(i);
        }
        for(long i : arr2){
            temp.add(i);
        }

        Collections.sort(temp);

        for (int i = 0; i < n; i++) {
            arr1[i] = temp.get(i);
        }

        for (int i = 0; i <m; i++) {
            arr2[i] = temp.get(n+i);
        }

        System.out.println(Arrays.toString(arr1));
        System.out.println(Arrays.toString(arr2));

    }
}
