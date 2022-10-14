class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); 
        if(n == 0) return 0; 
        sort(arr.begin(), arr.end()); 
        int mxLen = 0, currLen = 1; 
        for(int i = 1; i < n; i++) 
        {
            if(arr[i] == arr[i - 1] + 1) 
            {
                currLen++; 
            }
            else if(arr[i] != arr[i - 1]) 
            {
                mxLen = max(mxLen, currLen);
                currLen = 1; 
            }
        }
        
        mxLen = max(mxLen, currLen);  
        return mxLen; 
    }
};