class Solution {
public:
    string minWindow(string s, string t) {
        int s1=s.length();
        int t1=t.length();
        
        string str;
        int c=0,beg=0,res=-1;
        int mini=INT_MAX;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(auto it:t)
        {
            m1[it]++;
        }
        
        for(int i=0;i<s1;i++)
        {
            if(c<t1){
               m2[s[i]]++;
            
                    if(m1.find(s[i])!=m1.end() && m2[s[i]]<=m1[s[i]])
                        c++;
                }
            while(c==t1 && beg<=i)
            {
                if(i-beg+1<mini){
                    mini=i-beg+1;
                    res=beg;
                }
                m2[s[beg]]--;
                if(m1.find(s[beg])!=m1.end() && m2[s[beg]]<m1[s[beg]])
                
                    c--;
                
                beg++;
                    
                
            }
        }
        if(mini==INT_MAX)
            return "";
        return s.substr(res,mini);
    }
};
