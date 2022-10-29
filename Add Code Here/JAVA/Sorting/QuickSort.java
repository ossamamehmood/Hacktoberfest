import java.util.Arrays;

public class QuickSort {
    public static void main(String[] args) {
        int[] arr = {13, 18, 27, 2, 19, 25};
        int n = arr.length;
        System.out.println(Arrays.toString(arr));
        quick(arr, 0, n - 1);
        System.out.println(Arrays.toString(arr));
    }

    private static void quick(int[] arr, int start, int end) {
        if (start < end) {
            int p = partition(arr, start, end);
            quick(arr, start, p - 1);
            quick(arr, p + 1, end);
        }
    }

    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        return i + 1;
    }
}
