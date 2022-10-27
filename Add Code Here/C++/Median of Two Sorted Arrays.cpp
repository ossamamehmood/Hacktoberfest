class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        double ans;
        if(n%2==0){
            int a=n/2;
            int b=a-1;
            ans=(nums1[a]+nums1[b])/2.0;
        }
        else{
            int k=n/2;
            ans=nums1[k];
            
        }
        return ans;
        
       
    }
    
};