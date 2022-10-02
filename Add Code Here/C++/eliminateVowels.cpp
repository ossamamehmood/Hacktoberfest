#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstring>
using namespace std;
int vowelChk(char);
int main(){
   char s[50], t[50];
   int c, d = 0;
   cout<<"Enter a string to delete vowels\n";
   cin>>s;
   for(c = 0; s[c] != '\0'; c++) {
      // check for If not a vowel
      if(vowelChk(s[c]) == 0){
         t[d] = s[c];
         d++;
      }
   }
   t[d] = '\0';
   strcpy(s, t);
   cout<<"String after delete vowels:"<<s;
   return 0;
}
int vowelChk(char ch){
   if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' || ch == 'u' || ch == 'U')
      return 1;
   else
      return 0;
}
