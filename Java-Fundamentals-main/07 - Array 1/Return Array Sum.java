public class Solution {
	
	public static int sum(int[] arr) {
		//Your code goes here
        
        int s = 0;
        
        for(int i=0;i<arr.length;i++)
            s += arr[i];
        
        return s;
        
	}
}