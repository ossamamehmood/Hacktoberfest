public class Solution {

	public static int countWords(String str) {	
		//Your code goes here
        
        int n = str.length();
        int res = 0;
        
        if(n==0)
            return res;
        else
            res++;
        
        for(int i=0;i<n;i++)
        {
            if(str.charAt(i)==' ')
                res++;
        }
        return res;
        
	}

}