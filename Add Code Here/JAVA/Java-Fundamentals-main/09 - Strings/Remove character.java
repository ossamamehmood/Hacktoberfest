public class Solution {

	public static String removeAllOccurrencesOfChar(String str, char ch) {
		// Your code goes here
        
        String res = "";
        
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i) != ch)
                res += str.charAt(i);
        }
        
        return res;
        
	}

}