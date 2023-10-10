#include <iostream>
#include <vector>

// Function to partition the array into two sub-arrays and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the pivot element (usually the last element)
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }

    // Place the pivot element in its correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform the quicksort algorithm
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quicksort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
