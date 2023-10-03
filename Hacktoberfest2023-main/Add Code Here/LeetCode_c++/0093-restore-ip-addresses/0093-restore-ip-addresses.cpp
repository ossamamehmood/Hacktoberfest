class Solution {
public:
    
    bool check ( string str)
    {
        if( str.size() >3 || str.size()==0)
         return false;

        if(stoi(str)>255 || stoi(str)<0)
         return false;
        if( str.size()>1 && str[0]=='0')
         return false; 
            
        return true;
    }
    void solve( string s, vector<string>&ans,string temp ,int count,int index)
    {
       if( count==3)
        {
            if(check(s.substr(index)))
              ans.push_back( temp +s.substr(index));
            
            return ;
        }
        int sz= s.length();
        for( int i =index;i <min( sz, index+3);i++)
        {
            if( check (s.substr(index,i-index+1)))
            {
              temp.push_back(s[i]);
              temp.push_back('.');
              solve( s,ans,temp,count+1,i+1);
              temp.pop_back();
            }
           
        }

    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string>ans;
        if(s.length()>12)
         return ans;

        string temp="";

        solve( s,ans,temp,0,0);
        return ans;
    }
};