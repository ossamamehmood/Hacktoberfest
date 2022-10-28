import java.util.Arrays;

public class RecursiveQuicksort {
    public static void main(String[] args) {
        int[] arr = {23, 59, 0, 0, 34, 57, 2, 56};
        quicksort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }

    static void quicksort(int[] arr, int l, int h) {
        if (l >= h) {
            return;
        }
        int s = l;
        int e = h;
        int m = s + ((e - s) / 2);
        int pivot = arr[m];
        while (s <= e) {
            while (arr[s] < pivot) {
                s++;
            }
            while (arr[e] > pivot) {
                e--;
            }
            if (s <= e) {
                int temp = arr[s];
                arr[s] = arr[e];
                arr[e] = temp;
                s++;
                e--;
            }
        }
        quicksort(arr, l, e);
        quicksort(arr, s, h);
    }

}
