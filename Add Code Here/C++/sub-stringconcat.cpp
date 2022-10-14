#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
class Solution {
public:
   bool ok(string s, unordered_map <string, int> wordCnt, int n){
      string temp = "";
      for(int i = 0; i < n; i++){
         temp += s[i];
      }
      for(int i = n; i < s.size(); i++){
         if(temp.size() % n == 0){
            if(wordCnt.find(temp) == wordCnt.end())return false;
         else{
            if(wordCnt[temp] == 1){
               wordCnt.erase(temp);
               temp = "";
            }
            else{
               wordCnt[temp]--;
               temp = "";
            }
         }
      }
      temp += s[i];
   }
   if(wordCnt.find(temp) == wordCnt.end())return false;
   else{
      if(wordCnt[temp] == 1){
         wordCnt.erase(temp);
         temp = "";
      }
      else{
         wordCnt[temp]--;
         temp = "";
      }
   }
   return wordCnt.size() == 0;
}
vector<int> findSubstring(string a, vector<string> &b) {
   if(a.size() == 0 || b.size() == 0)return {};
      unordered_map <string, int> wordCnt;
   for(int i = 0; i < b.size(); i++)wordCnt[b[i]]++;
      vector <int> ans;
   int window = b.size() * b[0].size();
   string temp ="";
   for(int i = 0; i < window; i++)temp += a[i];
   for(int i = window; i < a.size(); i++){
      if(temp.size() % window == 0 && ok(temp, wordCnt, b[0].size())){
         ans.push_back(i - window);
      }
      temp += a[i];
      if(temp.size() > window)temp.erase(0, 1);
   }
   if(temp .size() % window ==0 && ok(temp, wordCnt, b[0].size()))ans.push_back(a.size() - window);
      return ans;
   }
};
main(){
   vector<string> v = {"foo", "bar"};
   Solution ob;
   print_vector(ob.findSubstring("barfoothefoobarman", v));
}
Footer
