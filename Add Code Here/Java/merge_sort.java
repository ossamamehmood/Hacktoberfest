package Sorting;

import java.util.Scanner;

public class merge_sort {
    static void mergeSort(int arr[], int start, int end)
    {
        int mid;
        if(start<end){
            mid=(start+end)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }

    }
    static void merge(int arr[],int start,int mid, int end)
    {
        int [] b=new int[100];
        int i=start,j=mid+1,k=start;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                b[k++]=arr[i++];
            }
            else
                b[k++]=arr[j++];
        }
        if(i>mid){
            while(j<=end){
                b[k++]=arr[j++];
            }
        }
        else{
            while(i<=mid)
                b[k++]=arr[i++];
        }
        for(i=start;i<=end;i++){
            arr[i]=b[i];
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = input.nextInt();
        int [] arr = new int[n];
        int i;
        System.out.print("Enter "+ n + " element of array: ");
        for(i=0;i<n;i++)
            arr[i]= input.nextInt();
        mergeSort(arr,0,n-1);
        System.out.print("Sorted elements are: ");
        for(i=0;i<n;i++)
            System.out.print(arr[i]+ " ");
    }
}
