package JAVA;

import java.util.*;

public class String_Palindrome_Two_Pointer
{
    public static boolean ispal( String str ) {
        for( int i = 0, n = str.length(); i < n; ++i ) {
            if( str.charAt(i) != str.charAt(n-1-i) )
                return false;
        }
        return true;
    }
    
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
		System.out.print("Enter a String value: ");
		String str = in.nextLine();
		System.out.println( str + " is " + (ispal(str) ? "\b" : "not") + " a palindrome.");
	}
}
