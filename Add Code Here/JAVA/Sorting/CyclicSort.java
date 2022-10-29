import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = {5,4,3,2,1};
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void cyclicSort(int[] arr){
        int i = 0;
        while(i < arr.length){
            //arr[arr[i] - 1] = arr[correct index]
            if(arr[i] != arr[arr[i] - 1]){
                swapArray(arr,i,arr[i] - 1);
            }else {
                i++;
            }
        }
    }
    static void swapArray(int[] arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
