#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Interpolation Search function
int interpolationSearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

// Meta Binary Search function
int metaBinarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = interpolationSearch(arr, left, right, target);

        // If target is found
        if (mid != -1) {
            return mid;
        }

        // If target is less than the element at mid, search in the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is greater than the element at mid, search in the right half
        else {
            left = mid + 1;
        }
    }

    // If target is not found in the array
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    // Perform Meta Binary Search
    int index
