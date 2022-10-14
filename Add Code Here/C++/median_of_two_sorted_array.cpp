class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
                i++;
            }
        }
        while(j<nums2.size()){
            nums1.insert(nums1.end(),nums2[j]);
            j++;
        }
        if(nums1.size()%2==0){
            return ( double(nums1[nums1.size()/2]) + double(nums1[(nums1.size()/2)-1]) )/2;
        }
        else{
            return double(nums1[nums1.size()/2]);
        }
    }
};
