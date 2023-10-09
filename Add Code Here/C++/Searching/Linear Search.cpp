#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return true; // Element found
        }
    }
    return false; // Element not found
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the element you want to search for: ";
    cin >> target;

    if (linearSearch(arr, n, target)) {
        cout << target << " is present in the array." << endl;
    } else {
        cout << target << " is not present in the array." << endl;
    }

    return 0;
}
