function binarysearch(arr,start,end,target){
    const mid=Math.floor((start+end)/2);
    if(start>end){
        return -1;
    }
   if(target===arr[mid]){
       return mid;
   }
   if(target>arr[mid]){
    return binarysearch(arr,mid+1,end,target);
   }
   else{
    return binarysearch(arr,start,mid-1,target);
   }
}
arr=[1,2,3,4,5]

console.log(binarysearch(arr,0,arr.length-1,5))
