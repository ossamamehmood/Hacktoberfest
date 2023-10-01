class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
         stack<int>st;
         for( int i=0;i<tokens.size();i++)
         {
             if( tokens[i]=="+"|| tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
             {
               int a = st.top();
               st.pop();
               int b = st.top();
               st.pop();

               if( tokens[i]=="+")
                st.push(a+b);
               else if( tokens[i]=="-")
                st.push(b-a);
               else if( tokens[i]=="*")
                st.push(a*b);
               else if( tokens[i]=="/")
                st.push(b/a); 
             }
             else 
              {
                  st.push(stoi(tokens[i]));
              }
         }
         return st.top();
    }
};