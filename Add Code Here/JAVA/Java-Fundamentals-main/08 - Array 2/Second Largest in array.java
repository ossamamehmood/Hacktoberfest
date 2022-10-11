public class Solution {  

    public static int secondLargestElement(int[] arr) {
    	//Your code goes here
        
        int n = arr.length;
        
        int f = Integer.MIN_VALUE;
        int s = Integer.MIN_VALUE;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>f)
            {
                s = f;
                f = arr[i];
            }
            else if(arr[i]>s && arr[i]!=f)
            {
                s = arr[i];
            }
        }
        
        return s;
        
    }

}