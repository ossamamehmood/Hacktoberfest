#include <iostream>
#include <cmath>

using namespace std;

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int target) {
    // Calculate the block size for jumping
    int jump = sqrt(n);

    // Initialize variables for left and right pointers
    int left = 0;
    int right = 0;

    // Jump to the right block until the target is greater than the current block's last element
    while (right < n && arr[right] < target) {
        left = right; // Update left pointer to the start of the current block
        right += jump; // Jump to the next block
    }

    // Perform linear search in the current block
    for (int i = left; i < min(right, n); ++i) {
        // If target element is found, return its index
        if (arr[i] == target) {
            return i;
        }
    }

    // If target element is not in the array, return -1
    return -1;
}

// Main function
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Perform Jump Search
    int index = jumpSearch(arr, n, target);

    // Output the result
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
