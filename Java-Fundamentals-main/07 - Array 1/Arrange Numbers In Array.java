import java.lang.Math;

public class Solution {
    
    public static void arrange(int[] arr, int n) {
    	//Your code goes here
        int s = 1;
        
        if(n%2 == 0)
        {
            for(int i=0;i<(int)Math.ceil(n/2);i++)
            {
                arr[i] = s;
                s += 2;
            }
        }
        else
        {
            for(int i=0;i<=(int)Math.ceil(n/2);i++)
            {
                arr[i] = s;
                s += 2;
            }
            
        }
        
        if(n%2 == 0)
            s = n;
        else
            s = n-1;
        
        
        if(n%2 != 0)
        {
            for(int i = (int)Math.ceil(n/2)+1;i<n;i++)
            {
                arr[i] = s;
                s -= 2;
            }
        }
        else
        {
            for(int i = (int)Math.ceil(n/2);i<n;i++)
            {
                arr[i] = s;
                s -= 2;
            }
        }
        
    }
}