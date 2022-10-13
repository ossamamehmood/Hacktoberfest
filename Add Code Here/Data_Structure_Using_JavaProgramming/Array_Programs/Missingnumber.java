// Java program to find missing number in an array.
//Solution:
// Find the sum of n number using formula n=n*(n+1)/2
// Find the sum of elements present in given array.
// Substract (sum of n numbers – sum of elements present in the array).

package Data_Structure_Using_JavaProgramming.Array_Programs;

class Missingnumber {

    public static void main(String[] args) {
 
        int[] arr1={7,5,6,1,4,2};
        System.out.println("Missing number from array arr1: "+missingNumber(arr1));
        int[] arr2={5,3,1,2};
        System.out.println("Missing number from array arr2: "+missingNumber(arr2));
 
    }
 
    public static int missingNumber(int[] arr)
    {
        int n=arr.length+1;
        int sum=n*(n+1)/2;
        int restSum=0;
        for (int i = 0; i < arr.length; i++) {
            restSum+=arr[i];
        }
        int missingNumber=sum-restSum;
        return missingNumber;
    }
}
 
