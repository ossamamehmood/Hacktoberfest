public class Solution {

	public static String reverseEachWord(String input) {
		//Your code goes here
        
        String ans ="";
        int s = 0;
        int i = 0;
        
        for(;i<input.length();i++)
        {
            if(input.charAt(i) == ' ')
            {
                String word = "";
                int end = i-1;
                for(int j=end;j>=s;j--)
                    word += input.charAt(j);
                word += " ";
                ans += word;
                s = i+1;
            }
            
        }
        
        String word = "";
        
        for(int j=input.length()-1;j>=s;j--)
            word += input.charAt(j);
        ans += word;
        
        return ans;
        
        
	}

}