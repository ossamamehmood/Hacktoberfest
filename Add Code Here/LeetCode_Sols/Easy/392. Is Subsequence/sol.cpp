#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    
    int n1 = s.length();
    int n2 = t.length();

    if(n1 < 1) return true;
    
    int i = 0;
    int j = 0;

    while(i < n2){
      if(t[i] == s[j]){
        j++;
      }
      i++;
      if(j == n1) return true;
    }
    
    return false;
  }
};

int main() {

// call the fn here

  return 0;
}