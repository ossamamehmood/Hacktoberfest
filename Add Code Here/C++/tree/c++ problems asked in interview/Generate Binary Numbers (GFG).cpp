Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2
Output: 
1 10
Explanation: 
Binary numbers from
1 to 2 are 1 and 10.

Example 2:

Input:
N = 5
Output: 
1 10 11 100 101
Explanation: 
Binary numbers from
1 to 5 are 1 , 10 , 11 , 100 and 101.
 

Your Task:
You only need to complete the function generate() that takes N as parameter and returns vector of strings denoting binary numbers.

Expected Time Complexity : O(N log2N)
Expected Auxilliary Space : O(N log2N)
  
Solution :

vector<string> generate(int N)
{
	queue<string>q;
	vector<string>v;
	
	q.push("1");
	while(N--)
	{
	    string s = q.front();
	    v.push_back(s);
	    q.pop();
	    q.push(s+"0");
	    q.push(s+"1");
	}
	return v;
}
