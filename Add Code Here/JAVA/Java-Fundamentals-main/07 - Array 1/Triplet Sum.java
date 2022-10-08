public class Solution {
    
    public static int findTriplet(int[] arr, int x) {
    	//Your code goes here
        
        int n = arr.length;
        int res = 0;
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(arr[i]+arr[j]+arr[k] == x)
                        res++;
                }
            }
        }
        return res;
    }

}