package LEasy;//package CC;
//
//import java.util.HashMap;
//
//public class MajorityElementArr {
//    public static void bruteforce(int[] arr,int n){
//        int counter = 0;
//        for (int i = 0; i < n; i++) {
//
//            counter = 0;
//            for (int j = 0; j < n; j++) {
//
//                if (arr[j] == arr[i]) {
//                    counter++;
//                }
//
//            }
//
//        }
////        System.out.println(counter);
//        if(counter>n/2){
//            System.out.println("counter is "+counter);
//        }
//    }
//    private static void better(int[] arr, int n) {
//
//        HashMap<Integer,Integer> mpp=new HashMap<>();
//        for (int i = 0; i < arr.length; i++) {
//            mpp.put(arr[i]++);
//        }
//        System.out.println(mpp);
//
//
//
//
//    }
//    public static void main(String[] args) {
//
//        int[] arr = {2, 2, 3, 3, 1, 2, 2};
//        int n = arr.length;
//
////        bruteforce(arr,n);
//
//        better(arr,n);
//
//
//    }
//
//
//}
//
//
