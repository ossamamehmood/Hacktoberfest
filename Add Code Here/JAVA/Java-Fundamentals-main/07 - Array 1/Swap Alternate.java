import java.util.Scanner;

public class Solution {
    
    public static void swapAlternate(int arr[]) {
    	//Your code goes here
        
        
        int n = arr.length;
    
        
        if(n%2 == 0)
            n -= 2;
        else
            n -= 3;
        
        for(int i=0;i<=n;i+=2)
        {
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
        
        
        
        
    }
}