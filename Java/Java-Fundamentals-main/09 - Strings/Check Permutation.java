
public class Solution {

	public static boolean isPermutation(String str1, String str2) {
		//Your code goes here
        
        int n1 = str1.length();
        int n2 = str2.length();
        
        int arr1[] = new int[26];
        int arr2[] = new int[26];
        
        for(int i=0;i<n1;i++)
        {
            char ch = str1.charAt(i);
            arr1[ch-'a']++;
        }
        
        for(int i=0;i<n2;i++)
        {
            char ch = str2.charAt(i);
            arr2[ch-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i])
                return false;
        }
        
        return true;
        
	}

}