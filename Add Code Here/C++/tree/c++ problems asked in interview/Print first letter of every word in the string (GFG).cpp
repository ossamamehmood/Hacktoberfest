Given a string S, the task is to create a string with the first letter of every word in the string.
Example 1:

Input: 
S = "geeks for geeks"
Output: gfg

Example 2:

Input: 
S = "bad is good"
Output: big

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function firstAlphabet() which takes string S as input parameter and returns a string that contains the first letter of every word in S.


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Solution :

class Solution{
public:	
	
	string firstAlphabet(string S)
	{
	    string ans;
	    ans+=S[0];
	    
	    for(int i=1;i<S.size();i++)
	    {
	        if(S[i-1]==' ')
	            ans+=S[i];
	    }
	    return ans;
	}
	
};
