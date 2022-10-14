function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    const a = [...nums1, ...nums2]
    .sort((a_,b_) => a_-b_)
   
   if(a.length % 2){
     return a[((a.length-1)/2)]
   }
   return (a[(a.length/2) - 1] + a[((a.length/2))])/2;
};