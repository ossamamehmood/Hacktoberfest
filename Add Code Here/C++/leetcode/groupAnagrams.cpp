#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    vector<string> temp;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(s);
    }
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans.push_back(it->second);
    }
    return ans;
}
int main()
{

    return 0;
}