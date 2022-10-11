public class Solution{  

    public static int findUnique(int[] arr){
		//Your code goes here
        
        int res = 0;
        
        for(int i=0;i<arr.length;i++)
            res ^= arr[i];
        
        return res;
        
    }
}