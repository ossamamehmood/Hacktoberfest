package LEasy;

import java.util.Arrays;

public class shiftarroneplace {
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5};
        int n=arr.length;

        bruteforce(arr);
        optimal(arr,n);






    }

    private static void optimal(int[] arr, int n) {


        int temp=arr[0];
        for (int i = 0; i < n-1; i++) {
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;

        System.out.println(Arrays.toString(arr));



    }

    private static void bruteforce(int[] arr) {

        int n=arr.length;
        int temp[]=new int[n];


        for (int i = 1; i < n; i++) {

            temp[i-1]=arr[i];
        }
        temp[n-1]=arr[0];

        System.out.println(Arrays.toString(temp));
    }
}
