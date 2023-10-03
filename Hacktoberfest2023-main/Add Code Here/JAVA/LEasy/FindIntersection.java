package LEasy;

import java.util.ArrayList;
import java.util.Arrays;

public class FindIntersection {
    public static void main(String[] args) {

        int[] arr1={1,2,3,4,5,6};
        int[] arr2={2,3,5,6,7,8};

//        bruteforce(arr1,arr2);
        optimal(arr1,arr2);



    }

    private static void optimal(int[] arr1, int[] arr2) {

        int i=0;
        int j=0;
        ArrayList<Integer> a=new ArrayList<>();

        while (i<arr1.length && j<arr2.length){


            if(arr1[i]<arr2[j]){
                i++;
            }else if(arr2[j]<arr1[i]){
                j++;
            }
            else {

                a.add(arr1[i]);
                i++;
                j++;

            }



        }
        for (int k:a) {
            System.out.print(k+" ");

        }


    }

    private static void bruteforce(int[] arr1, int[] arr2) {

        ArrayList<Integer> a=new ArrayList<>();
        int[] vis=new int[arr2.length];
        Arrays.fill(vis,0);
//        System.out.println(Arrays.toString(vis));
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2.length; j++) {


                if(arr1[i]==arr2[j] && vis[j]==0){

                    a.add(arr1[i]);
                    vis[j]=1;
                    break;

                }

            }

        }
        for (int i:vis){
            System.out.print(i);

        }
        System.out.println("");
        for(int i:a){
            System.out.print(i+" ");
        }

    }
}
