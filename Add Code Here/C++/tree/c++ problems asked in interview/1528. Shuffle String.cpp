Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

Example 1:

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
  
  
Solution : 
  class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for(int i=0;i<indices.size();i++)
        {
            res[indices[i]]=s[i];
        }
        return res;
    }
};
