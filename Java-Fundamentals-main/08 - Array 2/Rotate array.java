public class Solution {  

    public static void rotate(int[] arr, int d) {
    	//Your code goes here
        
        int n = arr.length;
        
        int tmp[] = new int[d];
        
        for(int i=0;i<d;i++)
            tmp[i] = arr[i];
        
        int s = d;
            
        for(int i=0;i<n-d;i++)
        {
            arr[i] = arr[s++];
        }
        
        int j = 0;
        
        for(int i=n-d;i<n;i++)
        {
            arr[i] = tmp[j++];
        }
            
        
    }

}