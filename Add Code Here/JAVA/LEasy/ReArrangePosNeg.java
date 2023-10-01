package LEasy;

import java.util.Arrays;

public class ReArrangePosNeg {
    public static void main(String[] args) {
        int[] arr={3,1,-2,-5,2,-4};
//        bruteforce(arr);

        optimal(arr);


    }

    private static void optimal(int[] arr) {

        int n=arr.length;
//        ArrayList<Integer> a=new ArrayList<>();
        int[] temp=new int[arr.length];

        int posidx=0,negidx=1;
        for (int i = 0; i < n; i++) {
            if(arr[i]<0){
                temp[negidx]=arr[i];
                negidx+=2;
            }
            else{
                temp[posidx]=arr[i];
                posidx+=2;
            }

        }

        System.out.println(Arrays.toString(arr));


    }


    private static void bruteforce(int[] arr) {
        int[] pos=new int[arr.length/2];
        int[] neg=new int[arr.length/2];
        int idx=0,idx2=0;
        for (int i = 0; i <arr.length ; i++) {

            if(arr[i]>0){
                pos[idx++]=arr[i];
            }else{
                neg[idx2++]=arr[i];
            }
        }
        System.out.println(Arrays.toString(pos));
        System.out.println(Arrays.toString(neg));

        for (int i = 0; i < arr.length/2; i++) {

            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];

        }
        System.out.println(Arrays.toString(arr));
//        int i=0;
//        idx=0;
//        idx2=0;
//        while (i<arr.length){
//
//            if(i%2!=0){
//                arr[i++]=pos[idx++];
//            }else{
//                arr[i++]=neg[idx2++];
//
//            }
//
//        }
    }
}
