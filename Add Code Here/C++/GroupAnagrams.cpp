#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        //string stores the chars of the anagram and the vector will store all the anagrams with the same chars
        for(auto i:strs){
            string temp=i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};