/*
    Problem Link:- https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
    
    Approach:- backtracking problem
    we will choose strings with no repetetion of characters if string has repetetion then we will go to next string
    else
    if it has no repetetions then we will have two options whether to take it or not for the maximum lengt of strings.
    
*/
class Solution 
{    
    public:
    void sol(int &ans,vector<string> &arr,int ind,vector<string> &st,vector<int> &stc)
    {
        if(ind>=arr.size())
            return;
        vector<int> z(26,0);
        for(int i=0;i<arr[ind].size();i++)
            z[arr[ind][i]-'a']++;
        int f=0;
        for(int i=0;i<26;i++)
        {
            if(stc[i]+z[i]>1)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            sol(ans,arr,ind+1,st,stc);
        }
        else
        {
            int ct=0;
            for(auto it:st)
                ct=ct+it.size();
            ct=ct+arr[ind].size();
            ans=max(ans,ct);
            for(int i=0;i<26;i++)
                stc[i]+=z[i];
            st.push_back(arr[ind]);
            sol(ans,arr,ind+1,st,stc);
            string z1=st.back();
            for(int i=0;i<z1.size();i++)
                stc[z1[i]-'a']--;
            st.pop_back();
            sol(ans,arr,ind+1,st,stc);
        }
    }
    int maxLength(vector<string>& arr) 
    {
        int ans=0;
        vector<string> st;
        vector<int> stc(26,0);
        sol(ans,arr,0,st,stc);
        return ans;
    }
};