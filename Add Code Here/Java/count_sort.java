package Sorting;

import java.util.Scanner;

public class count_sort {
    static void countsort(int arr[], int n, int max)
    {
        int i;
        int []sort = new int[10];
        int []count = new int[10];

        for(i=0;i<=max;i++){
            count[i]=0;
        }
        for(i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(i=1;i<=max;i++){
            count[i]=count[i]+count[i-1];
        }
        for(i=n-1;i>=0;i--){
            sort[count[arr[i]]-1]=arr[i];
            count[arr[i]]--;
        }

        for(i=0;i<n;i++)
            arr[i]=sort[i];

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n = input.nextInt();
        int [] arr = new int[n];
        int i, max=0;
        System.out.println("Enter "+ n + " element in array: ");
        for(i=0;i<n;i++) {
            arr[i] = input.nextInt();
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        countsort(arr, n, max);
        System.out.print("Sorted array: ");
        for(i=0;i<n;i++)
            System.out.print(arr[i]+ " ");
    }
}
