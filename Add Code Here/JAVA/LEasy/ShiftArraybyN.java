package LEasy;

import java.util.Arrays;

public class ShiftArraybyN {
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5,6};

        int n=arr.length;
        int d=3;
//        leftrotate(arr,n,d);
        optimizeshift(arr,n,d);




    }

    private static void reverse(int[] arr,int start,int end) {

        while (start<=end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;

        }
    }
    private static void optimizeshift(int[] arr, int n, int d) {
        reverse(arr, 0, d - 1);  // Reverse the first part
        reverse(arr, d, n - 1);  // Reverse the second part
        reverse(arr, 0, n - 1);  // Reverse the whole array
        System.out.println(Arrays.toString(arr));

        System.out.println(Arrays.toString(arr));
    }




    private static void leftrotate(int[] arr, int n, int d) {

        d=d%n;
        int temp[]=new int[d];
        for (int i = 0; i < d; i++) {
            temp[i]=arr[i];
        }
        for (int i = d; i <n; i++) {
            arr[i-d]=arr[i];
        }

        for (int i = n-d; i <n ; i++) {
            arr[i]=temp[i-(n-d)];
        }
        System.out.println(Arrays.toString(arr));






    }
}

