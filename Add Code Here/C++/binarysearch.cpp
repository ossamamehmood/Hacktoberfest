//Binary Search in CPP

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int value = 0, index = 0, val = 0;
        
        for(int i =0; i <= n; i++)
        {
            value = arr[i];
            if(k == value)
            {
                index = i;
                val = i;
            };
            val = i;
        };
        
        if(!index && val == n)
        {
          return -1;   
        }
        return index;
    }
};
