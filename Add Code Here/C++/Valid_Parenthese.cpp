class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for(auto i:s)  //iterate over each and every elements
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);  
            else
            {
               if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  
            }
        }
        return st.empty(); 
    }
    
};
