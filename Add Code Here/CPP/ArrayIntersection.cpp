#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> findIntersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> result_set;

    for (int num : nums2) {
        if (set1.count(num)) {
            result_set.insert(num);
        }
    }
    std::vector<int> result(result_set.begin(), result_set.end());
    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};

    std::vector<int> intersection = findIntersection(nums1, nums2);

    std::cout << "Intersection: ";
    for (int num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
