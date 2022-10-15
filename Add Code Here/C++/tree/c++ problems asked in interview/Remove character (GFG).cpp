Given two strings string1 and string2, remove those characters from first string(string1) which are present in second string(string2). 
Both the strings are different and contain only lowercase characters.
NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).

Example 1:

Input:
string1 = "computer"
string2 = "cat"
Output: "ompuer"
Explanation: After removing characters(c, a, t)
from string1 we get "ompuer".
Example 2:

Input:
string1 = "occurrence"
string2 = "car"
Output: "ouene"
Explanation: After removing characters
(c, a, r) from string1 we get "ouene".
 

Your Task:  
You dont need to read input or print anything. Complete the function removeChars() which takes string1 
and string2 as input parameter 
and returns the result string after removing characters from string2  from string1.

Expected Time Complexity:O( |String1| + |String2| )
Expected Auxiliary Space: O(K),Where K = Constant   

Constraints:
1 <= |String1| , |String2| <= 50
  
Solution :
class Solution {
  public:
    string removeChars(string string1, string string2) {
        int arr[26]={0};
        for(int i=0;i<string2.size();i++)
        arr[string2[i]-'a']++;
        
        string ans;
        for(int i=0;i<string1.size();i++)
        {
            if((arr[string1[i]-'a'])==0) // if value is greater than 0, that alphabet will be added to the new string 
            ans+=string1[i];
        }
        return ans;
    }
};
