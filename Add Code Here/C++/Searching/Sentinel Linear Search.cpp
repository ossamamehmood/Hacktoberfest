#include <iostream>
#include <vector>

using namespace std;

// Sentinel Linear Search function
int sentinelLinearSearch(vector<int>& arr, int target) {
    int n = arr.size();
    arr.push_back(target); // Add the target element at the end of the array as a sentinel

    int i = 0;
    // Loop through the array until the target is found
    while (arr[i] != target) {
        i++;
    }

    // Remove the sentinel element
    arr.pop_back();

    // If the index is less than the original size, the target is found, return its index
    if (i < n) {
        return i;
    }

    // If the index is equal to the original size, the target is not found, return -1
    return -1;
}

int main() {
    vector<int> arr = {4, 2, 7, 1, 9, 5, 3};
    int target = 7;

    // Perform Sentinel Linear Search
    int index = sentinelLinearSearch(arr, target);

    // Output the result
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
