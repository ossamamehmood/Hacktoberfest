package com.company;

public class rotated_array {
    public static void main(String[] args) {
        int[] arr={6,7,1,2,3};
        int x1=findpos(arr,2);
        System.out.println(x1);


    }
    static int getpivot(int[] arr){
        int s=0;
        int e=arr.length-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[0]){
                s=e+1;

            }
            else{
                e=mid;
            }

        }
        return s;
    }
    static int findpos(int[] arr,int tgt){
        int a=getpivot(arr);
        if(tgt>arr[a] && tgt<arr[arr.length-1]){
            return bs(arr,a,arr.length-1,tgt);
        }
        else{
            return bs(arr,0,a-1,tgt);
        }
    }

    private static int bs(int[] arr, int pivot, int i, int tgt) {
        int st=pivot;
        int ed= i;
        while(st<ed){
            int mid=st+(ed-st)/2;
            if(arr[mid]==tgt){
                return mid;
            }
            else if(arr[mid]>tgt){
                ed=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return -1;
    }
}
