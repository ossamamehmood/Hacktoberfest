class SelectionSort {
    void selectionSort(int arr[]) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the element at index i
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
        SelectionSort obj = new SelectionSort();
        int arr[] = { 64, 34, 25, 12, 9, 11, 90 };
        obj.selectionSort(arr);
        System.out.println("Sorted array");
        obj.printArray(arr);
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)