class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size(),n2=nums2.size();
         
         if(n1>n2)
          return findMedianSortedArrays(nums2,nums1);

        int n = n1+n2;
        int left = (n+1)/2;
         
        int low=0 ,high=n1;

        while(low<=high)
        {
            int mid1=(low+high)>>1;
            int mid2= left-mid1;

            int l1 =INT_MIN ,l2=INT_MIN ,r1=INT_MAX,r2=INT_MAX;

            if( mid1 <n1)
             r1=nums1[mid1];
            if( mid2 <n2)
             r2=nums2[mid2];

            if(mid1>=1) 
             l1=nums1[mid1-1];
            if(mid2>=1)
             l2=nums2[mid2-1];

             if( l1<= r2 && l2<=r1 ) 
              {
                  if(n%2==1)
                   return max(l1,l2);
                  else
                  return (double)(max(l1,l2)+min(r1,r2)) /2; 
              }

              else if( l1>r2)
               high =mid1-1;
              else 
              low=mid1+1; 

        } 
         return 0;

        //---------
    //    int n = nums1.size();
    //    int m = nums2.size();
    //    int size =n+m ;

    //    int idx1 = size/2;
    //    int idx2 = (size/2)-1;

    //    int element1 =0;
    //    int element2 =0;

    //    int i=0;
    //    int j=0;
    //    int k=0;

    //    while( i<n && j<m )
    //    {
    //        if( nums1[i]<nums2[j])
    //        {
    //             if(k==idx1)
    //              element1=nums1[i];
    //             if(k==idx2)
    //              element2=nums1[i];

    //             i++;  
    //        }
    //        else
    //        {
    //             if(k==idx1)
    //              element1=nums2[j];
    //             if(k==idx2)
    //              element2=nums2[j];

    //             j++;  
    //        }
    //        k++;
    //    }
    //    while( i<n )
    //    {
    //         if(k==idx1)
    //           element1=nums1[i];
    //         if(k==idx2)
    //           element2=nums1[i];

    //             i++;
    //             k++;
    //    }
    //     while( j<m )
    //    {
    //         if(k==idx1)
    //           element1=nums2[j];
    //         if(k==idx2)
    //           element2=nums2[j];

    //             j++;
    //             k++;
    //    }
    // //    cout<<element1<<" "<<element2;
    //    if( size% 2== 1)
    //     return element1;
    //    else 
    //     return (element1+element2) /2.0 ; 

    }
};