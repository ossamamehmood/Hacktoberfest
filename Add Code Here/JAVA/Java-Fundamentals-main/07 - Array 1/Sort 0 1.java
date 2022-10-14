public class Solution {  

    public static void sortZeroesAndOne(int[] arr) {
    	//Your code goes here
        
        int z = 0;
        int n = arr.length;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
                z++; 
        }
        
        for(int i=0;i<z;i++)
            arr[i] = 0;
        for(int i=z;i<n;i++)
            arr[i] = 1;
        
        
    }
}