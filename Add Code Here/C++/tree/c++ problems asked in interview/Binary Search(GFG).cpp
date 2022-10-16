Given a sorted array of size N and an integer K, find the position at which K is present in the array using binary search.


Example 1:

Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.
  
Solution :

class Solution{
public:
    int binarysearch(int arr[], int n, int k){
        int start = 0 , end  = n-1 , mid =0;
        while(start<=end)
        {
            mid = (start+end)/2;
            
            if(arr[mid]==k)
            return mid;
            
            else if(k>arr[mid])
            start = mid+1;
            
            else 
            end = mid-1;
        }
        return -1;
    }
};
