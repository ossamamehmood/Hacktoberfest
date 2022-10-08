public class Solution {  

    public static void pushZerosAtEnd(int[] arr) {
    	//Your code goes here
        
        
        int n = arr.length;
        int z = 0;
        int i = 0;
        
        for(int j=0;j<n;j++)
        {
            if(arr[j] == 0)
                z++;
            else
            {
                arr[i] = arr[j];
                i++;
            }
        }
        
        for(int j = n-z; j<n;j++)
            arr[j] = 0;
        
    }

}