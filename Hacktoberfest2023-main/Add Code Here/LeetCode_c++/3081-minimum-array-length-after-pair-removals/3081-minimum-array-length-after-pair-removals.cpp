class Solution {
public:
 /*Intuition
We store the count of the element that occurs maximum number of times.

Notice that if the count of max occuring element is less than n/2 times, then the element can be cancelled by remaining elements. In this case, if array size is even, then we say that ans is 0 and 1 incase the array size is odd. Because after cancelling all elements, 1 element is still remaining at the end.

If the element occurs more than n/2 times, so now it cannot cancel all elements. But it will still cancel all remaining elements.
How many elements are remaining? The elements remaining are (n - maxi). So elements left are maxi - (n - maxi) = 2*maxi - n;
*/
    int minLengthAfterRemovals(vector<int>& nums) 
    {
      int n=nums.size();
      // unordered_map<int,int>mp;
      // for( auto i : nums)
      //  mp[i]++;   
      
      // int mx=0;
      //  for( auto it:mp)
      //   mx= max(mx,it.second);

      // if( mx <= n/2 )
      // {
      //     if( n%2 ==0 )
      //      return 0;
      //     else 
      //      return 1; 
      // }  
      // else 
      //  return 2* mx -n;

      int i=0,j=n/2;
      int del=0;

      while( i <n/2 && j<nums.size ())
      {
          if( nums[i] < nums[j])
          {
            i++;
            del+=2;
          }
          j++;
      }
      return n-del;
        
    }
};