class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
       // Calculate Total length of final array: O(N)
        int n1=nums1.size();  
        int n2=nums2.size();
        int n=n1+n2;  
      
        // Edge Cases
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2-1]+nums1[n1/2])/2.0;
        if(n1==0)
             return n2%2?nums2[n2/2]:(nums2[n2/2-1]+nums2[n2/2])/2.0;
        
        // Resize the array 'nums1': O(N), N is size of resized array
        nums1.resize(n);
        
        // Now use pointer to compare arrays elements 
        int i=0;
        int j=0;
        
       // Store all element in 'array 1' in sorted order 
        while(i<n1)  // O(n1)
        {
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i],nums2[0]);  // O(1)
                // Rearrange Array nums2
                rearrangeArray(nums2);  // O(n2)
            }
            i++;
        }
        
        // Store remaining elements of 'array 2' in 'array 1' 
        while(j<nums2.size()) // O(n2)
            nums1[i++]=nums2[j++];
        
    // Return Result
    return n%2?nums1[n/2]:(nums1[n/2-1]+nums1[n/2])/2.0;
        
    }
    
    void rearrangeArray(vector<int>&nums2)
    {
        // Using insertion sort for insertion 
           // worst case Time Complexity Would be: O(n)
        for(int i=1;i<nums2.size()&&nums2[i]<nums2[i-1];i++)
            swap(nums2[i],nums2[i-1]);
    }
};
