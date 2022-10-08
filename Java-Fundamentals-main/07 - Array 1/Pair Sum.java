public class Solution {  

    public static int pairSum(int arr[], int x) {
    	//Your code goes here
        
        int res = 0;
        int n = arr.length;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j] == x)
                    res++;
            }
        }
        return res;
        
    }
}