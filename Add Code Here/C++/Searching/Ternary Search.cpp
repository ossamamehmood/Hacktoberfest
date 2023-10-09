#include <iostream>
using namespace std;

bool ternarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target || arr[mid2] == target) {
            return true; // Element found
        }
        
        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target); // Search in the first third
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target); // Search in the last third
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target); // Search in the middle third
        }
    }
    return false; // Element not found
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the sorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the element you want to search for: ";
    cin >> target;

    if (ternarySearch(arr, 0, n - 1, target)) {
        cout << target << " is present in the array." << endl;
    } else {
        cout << target << " is not present in the array." << endl;
    }

    return 0;
}
