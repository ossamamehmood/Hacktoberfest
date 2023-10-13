package Sorting;

import java.util.Scanner;

public class Quick_sort {
    static void quicksort(int arr[], int start, int end )
    {
        int i,j,pivot,temp;
        if(start<end){
            pivot=start;
            i=start;
            j=end;

            while(i<j){
                while(arr[i]<=arr[pivot] && i<end)
                    i++;
                while(arr[j]>arr[pivot])
                    j--;
                if(i<j){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
            temp=arr[pivot];
            arr[pivot]=arr[j];
            arr[j]=temp;

            quicksort(arr,0,j-1);
            quicksort(arr,j+1,end);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = input.nextInt();
        int [] arr = new int[n];
        int i;
        System.out.print("Enter "+ n +" element in array: ");
        for(i=0;i<n;i++){
            arr[i]= input.nextInt();
        }
        System.out.print("Sorted array: ");
        quicksort(arr,0,n-1);
        for(i=0;i<n;i++){
            System.out.print(arr[i]+ " ");
        }
    }
}
