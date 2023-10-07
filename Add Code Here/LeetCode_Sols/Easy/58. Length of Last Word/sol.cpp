#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    
    int count = 0;
    int i = s.length() - 1;
    
    while(i >= 0) {
      char ch = s[i];
      
      if(ch == ' ' && count == 0) {
        i--;
        continue;
      }
      
      if(ch != ' ') {
        count++;
        i--;  
      } else {
        return count;
      }
    }
    
    return count;
  }
};

int main() {
  string s = "Hello World";
  
  Solution sol;
  int result = sol.lengthOfLastWord(s);
  
  cout << result << endl;
  
  return 0;
}