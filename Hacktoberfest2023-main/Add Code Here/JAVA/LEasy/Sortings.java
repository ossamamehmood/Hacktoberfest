package LEasy;

import java.util.ArrayList;
import java.util.Arrays;

public class Sortings {
    public static void main(String[] args) {
        int[] arr={ 5,4,3,2,1};
        int n=arr.length;
//        sorting(arr,n);

//        bubblesort(arr,n);
//        insertionsort(arr,n);
//        mergesort(arr,0,n-1);
        quicksort(arr,0,n-1);
        System.out.println(Arrays.toString(arr));
//        System.out.println(Arrays.toString(arr));



    }

    private static void quicksort(int[] arr, int low, int high) {

        if(low<high){
            int pidx=partition(arr,low,high);
            quicksort(arr,low,pidx-1);
            quicksort(arr,pidx+1,high);
        }
    }

    private static int partition(int[] arr, int low, int high) {

        int pivot=arr[low];
        int i=low;
        int j=high;

        while (i<j){
            while (arr[i]<=pivot && i<=high-1){
                i++;
            }

            while (arr[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

        }
        int temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;

        return j;

    }

    private static void mergesort(int[] arr, int low,int high) {
        if(low>=high){
            return;
        }
//        int mid=(low+high)/2;
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);






    }


    private static void merge(int[] arr, int low, int mid, int high) {

        ArrayList<Integer> temp=new ArrayList<>();
        int left=low;
        int right=mid+1;

        while (left<=mid && right<=high){

            if (arr[left]<=arr[right]){

                temp.add(arr[left]);
                left++;

            }else{
                temp.add(arr[right]);
                right++;
            }
        }


        while (left<=mid){
            temp.add(arr[left]);
            left++;
        }

        while (right<=high){
            temp.add(arr[right]);
            right++;
        }


        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }

    }

    private static void insertionsort(int[] arr, int n) {
        for (int i = 0; i <=n-1; i++) {
            int j=i;
            while (j>0 && arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                j--;
            }

        }

    }

    private static void bubblesort(int[] arr, int n) {

        boolean swapped=false;
        for (int i = 0; i < n-1; i++) {

            swapped=false;
            for (int j = 0; j < n-i-1; j++) {
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swapped=true;
                }
                
            }
            if(swapped==false){
                break;
            }
                

            
        }
        
    }

    private static void sorting(int[] arr, int n) {
        for (int i = 0; i < n-1; i++) {

            int min=i;
            for (int j = i+1; j < n; j++) {
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}
