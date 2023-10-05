// Java program to sort an array
// using Merge sort
import java.util.*;
public class MergeSort {
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of array:");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter the element:");
        for(int i=0;i<n; i++){
            arr[i]=sc.nextInt();
        }

        divide(arr,0, n-1);
        System.out.println("Sorted Array:");
        for(int i=0; i<n; i++){
            System.out.println(arr[i]+" ");
        }
        System.out.println();
    }

    public static void divide(int arr[], int si, int ei){

        if(si>=ei){
            return;
        }
        int mid=si + (ei - si)/2;
        divide(arr, si, mid);
        divide(arr, mid+1, ei);
        conquer(arr, si, mid, ei);
        
    }
    public static void conquer(int arr[], int si, int mid, int ei){
        int merged[] = new  int [ei-si+1];           //[1,4,2,2]  indx=  3 - 0 +1 =4 (size of arr) 

        int idx1=si;
        int idx2=mid+1;
        int x=0;

        while(idx1 <=mid && idx2 <=ei){
            if(arr[idx1] <= arr[idx2]){
                merged[x] = arr[idx1];
                x++;
                idx1++;
            }else{
                merged[x]=arr[idx2];
                x++;
                idx2++;
            }
        }
        while(idx1<=mid){
            merged[x]=arr[idx1];
            x++;
            idx1++;
        }
        while(idx2<=ei){
            merged[x]=arr[idx2];
            x++;
            idx2++;
        }
        for(int i=0, j=si; i<merged.length; i++, j++){
            arr[j]=merged[i];
        }
        
    }
}

// This code is contributed by Md Tajuddin
/*
OUTPUT: 

Enter the size of array:5
Enter the element:
3 5 2 7 1
Sorted Array:
1 
2
3
5
7
 */