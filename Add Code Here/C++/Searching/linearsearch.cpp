#include <iostream>

// Function to perform a linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element if found
        }
    }
    return -1; // Return -1 if the target element is not found in the array
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        std::cout << "
