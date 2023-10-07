#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    // Target not found in the array
    return -1;
}

int main() {
    std::vector<int> arr = {2, 5, 7, 8, 10, 11, 14, 18, 20, 21, 24, 27,29};
    int target = 10;
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    
    return 0;
}