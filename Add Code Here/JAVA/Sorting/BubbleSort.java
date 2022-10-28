import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {

        int [] arr = {6,23,2,53,8,72,9};
        System.out.println("Unsorted Array :" + Arrays.toString(arr));
        bubble(arr);
        System.out.println("Sorted Array : " + Arrays.toString(arr));
    }

    public static void bubble(int [] arr){
        for (int i = 0; i < arr.length - 1 - i ; i++) {
           int flag = 0;
            for (int j = 0; j < arr.length - 1; j++) {
                if (arr[j] > arr[j+1]){
                   int  temp =  arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
                   flag = 1;
                }
            }
            if (flag == 0){
                break;
            }
        }
    }
}
