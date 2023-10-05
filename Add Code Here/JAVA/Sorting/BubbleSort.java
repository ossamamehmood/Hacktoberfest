class BubbleSort {
    void bubbleSort(int arr[]) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no two elements were swapped in inner loop, then the array is already sorted.
            if (!swapped) break;
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
        BubbleSort obj = new BubbleSort();
        int arr[] = {64, 34, 25, 12, 9, 11, 90};
        obj.bubbleSort(arr);
        System.out.println("Sorted array");
        obj.printArray(arr);
    }
}


// Time Complexity:

// Worst-Case: O(n^2) 
// Best-Case: O(n) 
// Average-Case: O(n^2)

// Space Complexity: O(1)