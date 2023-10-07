//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        // Let's create a freq map first
        unordered_map<char,int> mp;
        // inorder to keep track of highest freq element
        priority_queue<pair<int,char>> pq;
        
        string ans = "";
        //initialize map
        for(auto i:str) {
            mp[i]++;
        }
        
        //initialize heap
        for(auto i:mp) {
            pq.push(make_pair(i.second,i.first));
        }
        
        //till last pair
        while(pq.size() > 1) {
            // take the top most pair and block it
            auto block = pq.top();
            // pop out the pair
            pq.pop();
            //decrement its freq    
            block.first--;
            // append answer with character
            ans += block.second;
            
            // take the second highest freq pair
            auto temp = pq.top();
            // pop out the pair
            pq.pop();
            //decrement its freq    
            temp.first--;
            // append answer with character
            ans += temp.second;
            
            // if blocked pair has still freq left
            if(block.first)
                pq.push(block);
            
            // Similarly check for this one too
            if(temp.first)
                pq.push(temp);
        }
        // if there's some leftover
        if(pq.size()) {
            // if freq is one then we can accomodate
            if(pq.top().first == 1)
                ans+=pq.top().second;
            else 
                return "-1";
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends