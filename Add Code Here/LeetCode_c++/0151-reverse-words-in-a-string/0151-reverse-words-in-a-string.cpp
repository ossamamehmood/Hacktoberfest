class Solution {
public:
    string reverseWords(string s) 
    {
      stack< string> st;
      string temp="";
       for( int i=0;i<s.length();i++)
       {
           if( s[i]!=' ')
            temp+=s[i];
           // rather than searching for ' ' in next turn 
           // check for the next turn its will reduce computations  
           if( s[i] !=' ' && s[i+1]==' ' )
           {
               st.push(temp);
               temp="";
           }
       }   
    //      s=' '+s;
    //     for( int i=1;i<s.length();i++)
    //    { 
    //        if( s[i] ==' ' && s[i-1]!=' ' )
    //        {
    //            st.push(temp);
    //            temp="";
    //        }
    //       else if(s[i]!=' ')
    //         temp+=s[i];
    //    }   
        if( temp !="")
        st.push(temp);
        s="";
  
        while(st.size()>1)
        {
         s+= st.top()+" ";
         st.pop();
        }
        s+=st.top();
        return s;
    }
};