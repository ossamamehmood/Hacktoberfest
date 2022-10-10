/*You are given a string s and an integer k.
You can choose any character of the string and
change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the
same letter you can get after performing the above operations.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int findMaxIndex(int mp[])
    {

        int mx = 0;
        for (int i = 0; i < 26; i++)
            if (mp[i] >= mp[mx])
                mx = i;
        return mx;
    }
    int characterReplacement(string s, int k)
    {

        int mp[26] = {0};
        int l = 0, r = 0, n = s.length();
        int res = 0;

        while (l <= r && r < n)
        {

            mp[s[r] - 'A']++;
            int x = r - l + 1;
            x -= mp[findMaxIndex(mp)];
            //  cout<<x<<" ";
            if (x <= k)
            {
                res = max(res, r - l + 1);
                r++;
            }
            else
            {
                mp[s[l] - 'A']--;
                l++;
                mp[s[r] - 'A']--;
            }
        }
        return res;
    }
};

int main()
{
    string str = "ABAB";
    int k = 2;
    Solution obj;
    cout << obj.characterReplacement(str, k);

    return 0;
}
