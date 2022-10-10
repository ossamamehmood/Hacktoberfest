public class Solution {
	public static String reverseWordWise(String input) {
		// Write your code here
        
        String ans ="";
        int s = 0;
        int i = 0;
        
        for(;i<input.length();i++)
        {
            if(input.charAt(i) == ' ')
            {
                String word = "";
                int end = i-1;
                for(int j=s;j<=end;j++)
                    word += input.charAt(j);
                word += " ";
                ans = word + ans ;
                s = i+1;
            }
            
        }
        
        String word = "";
        
        for(int j=s;j<input.length();j++)
            word += input.charAt(j);
    	word += " ";
        ans = word+ans;
        
        return ans;   

	}
}
