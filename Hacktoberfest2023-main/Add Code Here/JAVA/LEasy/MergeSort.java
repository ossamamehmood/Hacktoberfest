package LEasy;

import java.util.ArrayList;
import java.util.Arrays;

public class MergeSort {
    public static void main(String[] args) {
        int[] arr={5,4,2,5,2,5,6,77};
        int n=arr.length-1;
        mergesort(arr,0,n);

        System.out.println(Arrays.toString(arr));
    }

    private static void mergesort(int[] arr, int low, int high) {
        if(low==high){
            return;
        }
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }

    private static void merge(int[] arr, int low, int mid, int high) {

        ArrayList<Integer> a=new ArrayList<>();
        int left=low;
        int right=mid+1;
        while (left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                a.add(arr[left]);
                left++;
            }else{
                a.add(arr[right]);
                right++;
            }
        }
        while (left<=mid){
            a.add(arr[left]);
            left++;
        }

        while (right<=high){
            a.add(arr[right]);
            right++;
        }

        for (int i = low; i <=high ; i++) {
            arr[i]=a.get(i-low);

        }

    }
}
