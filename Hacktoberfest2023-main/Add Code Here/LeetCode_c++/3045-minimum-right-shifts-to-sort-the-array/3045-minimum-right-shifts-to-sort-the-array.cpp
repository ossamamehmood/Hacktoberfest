class Solution {
public:
    int minimumRightShifts(vector<int>& nums) 
    {
    //   int n=nums.size();
    //     vector<int>temp =nums;
    //     sort(temp.begin(),temp.end());
    //     int count=0;
    //     int i;
    //     for( i=0;i<n;i++)
    //     {
    //          if( temp == nums )
    //          {
    //              return count;
    //          }
    //         nums.insert(nums.begin(),nums[n-1]);
    //         nums.erase(nums.end()-1);
    //         count++;
    //     }
    //     return -1;
     
      int n= nums.size();
      int pvtindex=0 ,pvtcount=0;

      for(int i=0;i<n-1;i++)
      {
          if( nums[i] > nums[i+1])
          {
              pvtindex=i+1;
              pvtcount++;
          }
      }
      if( pvtcount>1)
       return -1;
      if( pvtindex==0)
       return 0;
      if( nums[n-1]<=nums[0])
       return n-pvtindex;

      return -1;   
      
    }
};