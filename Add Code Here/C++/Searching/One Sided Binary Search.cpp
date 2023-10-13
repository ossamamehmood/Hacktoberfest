#include <iostream>
#include <vector>
using namespace std;

// Function to perform one-sided binary search
int oneSidedBinarySearch(vector<int>& arr, int target) {
    int left = 0; // Left pointer
    int right = arr.size() - 1; // Right pointer

    // Check if the target is within the array bounds
    if (target < arr[left] || target > arr[right]) {
        return -1; // Target is out of bounds
    }

    // Perform one-sided binary search
    while (left <= right) {
        // Calculate the mid point using a one-sided formula
        int mid = left + (target - arr[left]) * (right - left) / (arr[right] - arr[left]);

        // If the target is found
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is larger, move left pointer
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, move right pointer
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found in the array
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    // Perform one-sided binary search
    int index = oneSidedBinarySearch(arr, target);

    // Output the result
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
