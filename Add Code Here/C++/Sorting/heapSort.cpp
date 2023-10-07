#include <iostream>
#include <vector>


void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;     
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest element is not the root, swap them
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

       
        heapify(arr, n, largest);
    }
}


void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // For Building max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap 
    for (int i = n - 1; i > 0; i--) {
        
        std::swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
