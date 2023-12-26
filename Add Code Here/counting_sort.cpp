#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    string countingSort(string str){
        int maximum = (str[0] - 'a');
        for (int i=0; i<str.length(); i++)
        {
            maximum = max(maximum, (str[i] - 'a'));
        }  
        
        int count[maximum+1] = {0};
        for (int i=0; i<str.length(); i++)
            count[str[i]-'a']++;  // correct
        
        for (int i=1; i<=maximum; i++)
            count[i] += count[i-1];

        string ans[str.length()];
        for (int i=str.length()-1; i>=0; i--)
            ans[--count[(str[i]-'a')]] = str[i];

        string fans = "";
        for (int i=0; i<str.length(); i++)
            fans += ans[i];
        return fans;
    }
};
int main()
{
    Solution sol = Solution();
    cout << "Enter string : ";
    string str;
    getline(cin, str);
    string ans = sol.countingSort(str);
    cout << ans;
    return 0;
}
