class Solution{
    static String longestPalin(String S){
        // code here
        
        int i,n = S.length();
        
        boolean table[][] = new boolean[n][n]; // for storing whether it is palindrome or not
        
        //substrings with length 1 are always palindromes
        int maxLength = 1;
        for(i = 0; i< n;i++)
           table[i][i] = true;
           
        // for substrings of len 2 , need to check start = end (1st char = 2nd char)
        
        int startIndex = 0;
        for(i = 0;i<n-1;i++)
        {
            if(S.charAt(i) == S.charAt(i+1))
            {
                table[i][i+1] = true;
                int ln = 2;
                if(maxLength < ln)
                {
                    maxLength = 2;
                    startIndex = i;
                }
            }
        }
        
        // for len > 2 , startIndex = endIndex , inBoundary string should be palindrome
        // table[i+1][j-1] should br palindrome (inboundary string)
       
        int subLen ,j; //substring length 
        for(subLen = 3; subLen <= n ; subLen++)
        {
            //starting index
            for(i=0;i<n-subLen+1;i++)
            {
                j = i + subLen -1;
                if(table[i+1][j-1] && S.charAt(i) == S.charAt(j))
                {
                    table[i][j] = true;
                    
                    if(subLen > maxLength)
                    {
                        maxLength = subLen;
                        startIndex = i;
                    }
                }
            }
        }
        return S.substring(startIndex,startIndex+maxLength);
        
        
    }
}
