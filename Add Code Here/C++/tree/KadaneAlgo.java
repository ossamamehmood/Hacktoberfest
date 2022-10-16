class KadaneAlgo{
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        long currSum=0; //track current sum
        long sumSoFar=Long.MIN_VALUE;
        
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            
            if(currSum<arr[i]) currSum=arr[i]; //check current sum
            
            if(sumSoFar<currSum) sumSoFar=currSum; //update max sum
        }
        return sumSoFar;
        
    }
//     Time Complexity: O(N)
//     Auxiliary Space: O(1)
}

