Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
  
Time Complexity : O(|s|) where |s| is the length of the string given.
  
Solution :

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};  //using a count array to store the times the character is appearing , since there are 26 alphabets 
        
        for(char c:s) 
            count[c-'a']+=1; //traversing through each char and for eg, c = d so d-'a'= 3 which is the index at which incremenet will take place ; 0 is for a , 1 for b and so on
        
        for(int i=0;i<s.length();i++) 
        {
            if(count[s[i]-'a'] ==1) //checking the char which only has a count of 1 
                return i;
        }
        return -1;
    }
};
