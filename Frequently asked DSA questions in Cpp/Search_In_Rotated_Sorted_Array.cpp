// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554


#include <bits/stdc++.h> 
int getpivot(vector<int>& arr, int n)
{
   int left = 0,right = n-1;
   int mid = left + (right - left)/2;
   while(left<right)
   {
       if(arr[mid] >= arr[0])
       {
           left = mid + 1;
       }
       else {
           right = mid;
       }
       mid = left + (right - left)/2;
   }
   return left;
}
int binarysearch(vector<int>& arr, int s, int e, int key)
{
   int start = s, end = e;
   int mid = start + (end - start)/2;
   while(start <= end)
   {
       if(arr[mid] == key)
       {
           return mid;
       }
       else if(key > arr[mid])
       {
           start = mid + 1;
       }
       else 
       {
           end = mid - 1;
       }
       mid = start + (end - start)/2;
   }
   return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{
   int pivot = getpivot(arr,n);
   if(arr[pivot] <= k && arr[n-1] >= k)
   {
       return binarysearch(arr,pivot,n-1,k);
   }
   else
   {
       return binarysearch(arr,0,pivot-1,k);
   }
}