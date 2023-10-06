#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> merged(m + n);
        
        int i = 0; 
        int j = 0;
        int k = 0;

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            }
            else {
                merged[k++] = nums2[j++]; 
            }
        }
        
        while(i < m) {
            merged[k++] = nums1[i++];
        }
        
        while(j < n) {
            merged[k++] = nums2[j++];
        }
        
        int mid = merged.size() / 2;
        
        if(merged.size() % 2 == 0) {
            return (double)(merged[mid] + merged[mid - 1]) / 2;
        }
        else {
            return merged[mid];
        }
        
    }
};

int main() {

 // call the fn here

  return 0;
}