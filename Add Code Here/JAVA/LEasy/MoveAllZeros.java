package LEasy;

import java.util.ArrayList;
import java.util.Arrays;

public class MoveAllZeros {
    public static void main(String[] args) {
        int[] arr={1,2,0,0,4,5,0,2,5};
//        bruteforce(arr);

        optimal(arr);






    }

    private static void optimal(int[] arr) {

        int j=-1;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1){
            System.out.println("no zeros...");
        }
        for (int i = j+1; i <arr.length ; i++) {
            if(arr[i]!=0){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j++;
            }

        }
        System.out.println(Arrays.toString(arr));






    }

    private static void bruteforce(int[] arr) {

        ArrayList<Integer> a=new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            if(arr[i]!=0){
                a.add(arr[i]);
            }
        }

        for (int i=0;i<a.size();i++) {
            arr[i]=a.get(i);
        }
        for (int i = a.size(); i <arr.length ; i++) {

            arr[i]=0;

        }
        System.out.println(Arrays.toString(arr));




    }
}
