// Smallest window in a string containing all the characters of another string
#include "bits/stdc++.h"
using namespace std;
string smallestWindow (string s, string t)
    {
        int m[256] = { 0 };
 
    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0; // starting index of ans
    int count = 0;
   
    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }
 
    // References of Window
    int i = 0;
    int j = 0;
 
    // Traversing the window
    while (j < s.length()) {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
 
        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Sorting ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I
 
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
 
                i++;
            }
        }
        j++;
    }
 
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
    }


int main(){
    string s;
    cin>>s;
    string patt;
    cin>>patt;
    cout<<smallestWindow(s,patt);
}