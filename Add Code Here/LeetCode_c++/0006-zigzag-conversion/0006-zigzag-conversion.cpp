class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1) return s;
        // vector<string> row(n);
        // int j=0,d=1;
        // for( int i=0;i<s.size();i++)
        // {
        //     row[j] += s[i];
        //     if( j==n-1)
        //      d=-1;
        //     if( j==0)
        //      d=1;
        //     j+=d;  
        // }
        // s="";
        // for( int i=0;i<row.size();i++ )
        // {
        //     s+=row[i];
        // }
        // return s;

         string ans="";
         int diff = 2*(n -1);
         for( int i=0;i<n;i++)
         {
           if(i==0 || i==n-1)
           {
               for( int j=i;j<s.size();j=j+diff)
               {
                   ans.push_back(s[j]);
               }
           }
           else 
                {
                    bool first =1;
                    int gap1 = 2*(n-1-i);
                    int gap2 = 2*i;
                    int j=i;
                    while( j<s.length())
                    {
                        ans.push_back(s[j]);
                        if( first)
                         j+=gap1;
                        else 
                         j+=gap2;

                        first=!first;  
                    }
                }
         }
         return ans;
    }
};