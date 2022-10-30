//Program for Bubble Sort
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        int[] arr = {1,-2,3,-4,5,0};
        BubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void BubbleSort(int[] arr){
        boolean swapped; 
        //run the loop for n-1 times
        for (int i = 0; i < arr.length; i++) {
            //run internal loop
            swapped = false;
            for (int j = 1; j < arr.length - i; j++) {  //for less than n-i
                //swap if condition satisfy
                if(arr[j] < arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    swapped = true;
                }
            }
            //if swapped did not work that means array is soted then just break it.
            if(swapped == false){
                break;
            }
        }
    }
    
}
