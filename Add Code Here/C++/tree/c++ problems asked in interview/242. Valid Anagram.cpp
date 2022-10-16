Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
  
Solution :
Time Complexity - O(|s|) where |s| is the length of the string given.

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
            return false;
      
        int count1[26]={0};
        for(char ch:s)
            count1[ch-'a']++;
        
        int count2[26]={0};
        for(char ch: t)
            count2[ch-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=count2[i])
            {
                return false;
                break;
            }
        }
        return true;
    }
};


Solution :
1. When using linear search the time complexity becomes O(n*n) and space complexity as O(1)
2. When using sorting , time complexity is O(nlogn) and space complexity - O(1)
3. When using count array , time complexity is O(n) and space complexity is - O(1)
4. XOR concept does not work with this.
  
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={0};
        for(int i=0;i<s.size();i++)
        {
            cnt[s[i]-'a']++;
        }
        
        for(int i=0;i<t.size();i++)
        {
            cnt[t[i]-'a']--;
        }
        for(int i=0;i<=25;i++)
        {
            if(cnt[i]!=0)
                return false;
        }
        return true;
    }
};
