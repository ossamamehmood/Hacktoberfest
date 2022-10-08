public class Solution {

	public static String removeConsecutiveDuplicates(String str) {
		//Your code goes here
         
        String res = "";
		char ch = str.charAt(0);
		res += ch;
        
		for(int i = 1;i < str.length();i++) 
        {
			if(str.charAt(i) == ch);
			else 
				res += str.charAt(i);
			ch = str.charAt(i);
		}
		return res;
        
	}

}