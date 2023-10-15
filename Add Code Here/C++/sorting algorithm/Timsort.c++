#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::sort(arr.begin(), arr.end());

    std::cout << "Sorted Array: ";
    for (const int &num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}