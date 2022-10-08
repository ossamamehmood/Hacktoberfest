public class Solution {

	public static boolean isPalindrome(String str) {
		//Your code goes here
        
        String rev = "";
        
        for(int i=0;i<str.length();i++)
            rev = str.charAt(i) + rev;
        
        if(rev.equals(str))
            return true;
        else
            return false;
        
	}

}