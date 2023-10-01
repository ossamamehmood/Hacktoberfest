package LEasy;

import java.util.Arrays;

public class FindMissingnumber {
    public static void main(String[] args) {

        int [] arr={1,2,3};
        System.out.println(arr.length);
//        int n=4;
//        bruteforce(arr);

//        optimal(arr,n);


    }

    private static void optimal(int[] arr,int N) {

        Arrays.sort(arr);
        int n=arr.length;
        int ans=N*(N+1)/2;
        System.out.println(ans);
        int sum=0;
        for (int i = 0; i < n; i++) {
            sum+=arr[i];
        }
        System.out.println(ans-sum);
//        System.out.println(ans);
//        System.out.println(sum);


    }

    private static void bruteforce(int[] arr) {
        int flag=0;
        for (int i = 1; i < arr.length; i++) {
            flag=0;
            for (int j = 0; j < arr.length;j++) {

                if(arr[j]==i){
                flag=1;
                break;
                }
            }
            if(flag==0){
                System.out.println(i);
//                return i;
            }
        }





    }
}
