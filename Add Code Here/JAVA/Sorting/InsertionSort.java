class InsertionSort {
    void insertionSort(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            // Move elements of arr[0..i-1] that are greater than key
            // to one position ahead of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Prints the array
    void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        InsertionSort obj = new InsertionSort();
        int arr[] = {64, 34, 25, 12, 9, 11, 90};
        obj.insertionSort(arr);
        System.out.println("Sorted array");
        obj.printArray(arr);
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
