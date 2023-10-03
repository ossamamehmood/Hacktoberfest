// Problem Statement: Generate the longest possible substring from a given substring.

class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        
        if(n <2){
            return s;
        }
        
        int start =0, end =0;
        for(int i=0; i< n; i++){
            char c =s.charAt(i);
            int j=i, k=i;
            while(j >=0 && s.charAt(j) == c){
                j--;
            }
            while(k<n && s.charAt(k) ==c){
                k++;
            }
            
            while(j >=0 && k <n){
                if(s.charAt(j) != s.charAt(k)){
                    break;
                }
                j--;
                k++;
            }
            j++;
            if(end -start < k-j){
                end =k;
                start =j;
            }
        }
        return s.substring(start, end);
    }
}
