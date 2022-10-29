// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<string> v;
        MCM(s, v); // choose first partition and keep moving it
        return ans;
    }

    void MCM(string s, vector<string> &v)
    {
        // if size <= 1 that is no char left return
        if (s.size() <= 0)
        {
            return;
        }

        // when the string comes to an end char/end pal string then insert v to the ans matrix
        if (palindrome(s))
        {
            v.push_back(s);
            ans.push_back(v);
            v.pop_back();
        }

        // k = partition position
        for (int k = 1; k < s.size(); k++)
        {
            string t = s.substr(0, k);

            // if first part is a palin then only go for the rest
            if (palindrome(t))
            {
                v.push_back(t);
                MCM(s.substr(k, s.size() - k), v);
                v.pop_back();
            }
        }
    }

    bool palindrome(string &s)
    {
        int i = 0;
        int j = s.size() - 1;
        if (i == j)
            return true;
        if (i > j)
            return true;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}