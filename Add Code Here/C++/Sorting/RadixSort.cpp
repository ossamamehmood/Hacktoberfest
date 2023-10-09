#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum element in the array
int findMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort on the specified digit
void countingSort(vector<int>& arr, int exp) {
    const int base = 10; // The base for decimal numbers
    int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(base, 0);

    // Count the occurrences of each digit in the current place value
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % base]++;
    }

    // Calculate cumulative counts
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the counts and place elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    int max = findMax(arr);

    // Perform counting sort for each digit place value
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
