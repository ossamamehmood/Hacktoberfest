#include <iostream>
#include <vector>


void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    std::vector<int> left(n1);
    std::vector<int> right(n2);

   
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }

    
    int i = 0; 
    int j = 0; 
    int k = l; 

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Main function to perform merge sort
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        
        int m = l + (r - l) / 2;

        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        
        merge(arr, l, m, r);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
