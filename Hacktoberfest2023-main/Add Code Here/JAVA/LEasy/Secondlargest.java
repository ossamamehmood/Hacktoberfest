package LEasy;

import java.util.Arrays;

public class Secondlargest {



    public static void main(String[] args) {
        int[] arr={1,2,6,4,2,5,7};

//        System.out.println(bruteforce(arr));
//        System.out.println(better(arr));
        System.out.println(optimized(arr));
    }

    private static int optimized(int[] arr) {

        int largest=arr[0];
        int slargest=-1;

        for (int i = 1; i <arr.length ; i++) {


            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }else if(arr[i]<largest && arr[i]>slargest){
                slargest=arr[i];
            }

        }
        return slargest;
    }

    private static int better(int[] arr) {

        int largest=Integer.MIN_VALUE;
        int seclargest=-1;

        for (int i = 0; i < arr.length; i++) {

            if(arr[i]>largest){
                largest=arr[i];
            }
        }

        for (int i = 0; i <arr.length ; i++) {
            if(arr[i]>seclargest && arr[i]!=largest)
            {
                seclargest=arr[i];
            }
        }
        return seclargest;

    }


    private static int bruteforce(int[] arr) {
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        return arr[arr.length-2];
    }
}
