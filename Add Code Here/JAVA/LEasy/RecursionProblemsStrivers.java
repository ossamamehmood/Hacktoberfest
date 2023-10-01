package LEasy;

import java.util.Arrays;

public class RecursionProblemsStrivers {

//    public static void printNtimes(int i,int n){
//        if(i==n){
//            return;
//        }
//        System.out.println("hello world");
//        printNtimes(i+1,n);
//
//    }
    public static void printLinearly(int i,int n){
        if(i>n){
            return;
        }
        System.out.println(i);
        printLinearly(i+1,n);
    }
    public static void printLinearlydec(int i,int n){
        if(i>n){
            return;
        }
        printLinearlydec(i+1,n);
        System.out.println(i);
    }

    private static int functionalsum(int n) {

        if(n==0){
            return 0;
        }
        return n+functionalsum(n-1);
    }

    private static int fact(int n) {

        if(n==0){
            return 1;
        }
        return n*fact(n-1);
    }

    private static void sumofn(int i, int sum) {


        if(i<1){
            System.out.println(sum);
            return;
        }
        sumofn(i-1,sum+i);

    }



    private static void printuseBacktrackingdesc(int i, int n) {


        if(i>n){
            return;
        }
        System.out.println(i);
        printuseBacktrackingdesc(i+1,n);


    }

    private static void printuseBacktracking(int i, int n) {
        if(i<1){
            return;
        }
        printuseBacktracking(i-1,n);
        System.out.println(i);
    }
    private static void reversearr(int[] arr, int s, int e) {

        if(s>=e){
            System.out.println(Arrays.toString(arr));
            return;
        }
        swap(arr,s,e);
        reversearr(arr,s+1,e-1);

    }

    private static void swap(int[] arr, int s, int e) {
        int temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
    }

    private static void reversearroptimized(int[] arr, int s, int e) {
        if(s>=e/2){
            return;
        }
        int temp=arr[s];
        arr[s]=arr[e-s-1];
        arr[e-s-1]=temp;
        reversearroptimized(arr,s+1,e);


    }

    private static boolean palcheck(int i,String s) {

        if(i>=s.length()/2){
            return true;
        }
        if(s.charAt(i)!=s.charAt(s.length()-i-1)){
            return false;
        }
        return palcheck(i+1,s);
    }

    public static void main(String[] args) {
        int [] arr={1,2,3,4,5};
        int s=0;
        int e=arr.length;

//        reversearr(arr,s,e);

//        reversearroptimized(arr,s,e);
//        System.out.println(Arrays.toString(arr));

        System.out.println(palcheck(0,"madamamadam"));





//        printNtimes(0,n);
//        printLinearly(1,n);
//        printLinearlydec(1,n);

//        printuseBacktracking(5,n);
//        printuseBacktrackingdesc(0,n);

//        sumofn(5,0);

//        System.out.println(fact(5));

    }




}
