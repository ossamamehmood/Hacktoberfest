#include <bits/stdc++.h>
using namespace std;
int checkPalindrome(char str[], int first, int last){
   if (first < last + 1){
      first++;
      last--;
      return checkPalindrome(str, first, last);
   }

   if (first == last){
      return 1;
   }
   if (str[first] != str[last]){
      return 0;
   }
   return 1;
}
// Driver Code
int main(){
   char Str[] = "madam";
   int result;
   int length = strlen(Str);
   if (length == 0){
      result=1;
   }

   else{
      result=checkPalindrome(Str, 0, length - 1);
   }
   if (result==1){
      cout << "Input string is palindrome.";
   }
   else{
      cout << "Input string is not a palindrome.";
   }
   return 0;
}
