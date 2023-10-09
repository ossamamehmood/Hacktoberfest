package Sorting;

import java.util.Scanner;

public class bubble_sort {
    static void bubblesort(int arr[], int n, int i, int j)
    {
        int temp;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n = input.nextInt();
        int [] arr = new int[n];
        int i;
        System.out.print("Enter "+ n + " element of array: ");
        for(i=0;i<n;i++)
            arr[i]= input.nextInt();

        bubblesort(arr,n,0,n-1);
        System.out.print("sorted array: ");
        for(i=0;i<n;i++)
            System.out.print(arr[i]+ " ");
    }

}

