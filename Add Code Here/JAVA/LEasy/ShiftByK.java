package LEasy;

import java.util.ArrayList;
import java.util.Arrays;

public class ShiftByK {
    public static void main(String[] args) {

        int[] arr={1,2,3,4,5};
        int n=arr.length;
        ArrayList<Integer> temp1=new ArrayList<>();

        int k=2;

        for (int i = k; i < n; i++) {
            temp1.add(arr[i]);
        }
        for (int i = 0; i < k; i++) {
            temp1.add(arr[i]);
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i]=temp1.get(i);
        }
        System.out.println(Arrays.toString(arr));












    }

}
