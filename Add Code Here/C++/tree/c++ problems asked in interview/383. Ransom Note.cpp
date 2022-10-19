Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 
Solution : O(n) where n is the length of the string 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0}; //to store count of each alphabet 
        for(char ch:magazine)
            count[ch-'a']++; 
        
        for(char ch : ransomNote)
            if(count[ch-'a']-- <=0)
                return false;
        
        return true;
    }
};
