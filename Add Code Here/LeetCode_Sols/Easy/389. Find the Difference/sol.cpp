#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    char findTheDifference(string s, string t) {
      int sum1 = helper(s);
      int sum2 = helper(t);
      int diff = sum2 - sum1;
      return (char) diff;
    }

  private:
    int helper(string s) {
      int sum = 0;
      for(char c : s) {
        sum += c; 
      }
      return sum;
    }
};

int main() {
  // call the fn here
  
  return 0;
}