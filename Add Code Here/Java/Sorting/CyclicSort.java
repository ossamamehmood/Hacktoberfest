import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = {5,4,3,3,5,2,3,1,5,3};
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void cyclicSort(int[] arr){
        int i = 0;
        while(i<arr.length){
            int correctIndex = arr[i] -1;
            if (arr[i] != arr[correctIndex]){
                swap(arr, i, correctIndex);
            }else {
                i++;
            }
        }
    }
    static void swap(int arr[], int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    // Amazon Question [0,N]
    // Using mathematical approach
    static int missingNumber(int[] nums) {
        int actualSum = nums.length*(nums.length+1)/2;
        return actualSum - sum(nums);
    }
   static int sum(int[] arr){
        int sum = 0;
        for (int i = 0;i<arr.length;i++){
            sum = sum + arr[i];
        }
        return sum;
    }

}