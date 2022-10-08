public class Solution {

	public static char highestOccuringChar(String str) {
		//Your code goes here
        int n = str.length();
        
        int arr[] = new int[26];
        
        for(int i=0;i<n;i++)
        {
            char ch = str.charAt(i);
            arr[ch-'a']++;
        }
        
        int max  = 0;
        int maxindex = -1;
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]>max)
            {
                max = arr[i];
                maxindex = i;
            }
        }
        
        return (char)(maxindex+'a');
        
	}

}