public class InsertionSort {
      public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    public static void printArray(int[] ar) {
        for (int number : ar) {
            System.out.print(number + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = {19,20,22,17,99,20,3,69,2};
        System.out.println("Original array :");
        printArray(arr);
        insertionSort(arr);
        System.out.println("\nSorted array :");
        printArray(arr);
    }
}
