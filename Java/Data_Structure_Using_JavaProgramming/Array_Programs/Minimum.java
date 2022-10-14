// Find minimum element in a sorted and rotated array

package Data_Structure_Using_JavaProgramming.Array_Programs;

public class Minimum {
 
    public static void main(String[] args) {
    int arr[]={16,19,21,25,3,5,8,10};
    System.out.println("Minimum element in the array : "+findMinimumElementRotatedSortedArray(arr,0,arr.length-1,5));
    }
    public static int findMinimumElementRotatedSortedArray(int[] arr,int low,int high,int number)
    {
    int mid;
    while(low<high)
    {
    mid=low + ((high - low) / 2);
     
    if(arr[mid] > arr[high])
    {
    low=mid+1;
    }
    else
    {
    high=mid;
    }
    }
    return arr[low];
    }
    }
     