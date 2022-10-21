public class Solution {

    public static int arrayRotateCheck(int[] arr){
    	//Your code goes here
        
        int n = arr.length;
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
                return i+1;
        }
        
        return 0;
        
    }

}