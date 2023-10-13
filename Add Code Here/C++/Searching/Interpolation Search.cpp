#include <iostream>
using namespace std;

// Function to perform Interpolation Search
int interpolationSearch(int arr[], int n, int target) {
    int left = 0; // Left pointer
    int right = n - 1; // Right pointer
    
    // Find the position using interpolation formula
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Calculate the position with interpolation formula
        int pos = left + ((target - arr[left]) * (right - left) / (arr[right] - arr[left]));
        
        // If the target is found
        if (arr[pos] == target) {
            return pos;
        }
        
        // If the target is larger, update the left pointer
        if (arr[pos] < target) {
            left = pos + 1;
        }
        // If the target is smaller, update the right pointer
        else {
            right = pos - 1;
        }
    }
    
    // If the target is not found, return -1
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Perform Interpolation Search
    int index = interpolationSearch(arr, n, target);

    // Output the result
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
