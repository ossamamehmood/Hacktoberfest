#include <iostream>
#include <string>
using namespace std;

bool ispal ( string str )
{
  for( int i = 0, n = str.length(); i < n; ++i )
  {
    if( str[i] != str[n-1-i] )
      return false;
  }
  return true;
}

int main()
{
  string str;
  cout << "Enter a string: ";
  fflush(stdin);
  cin >> str; 
  cout << str << " is " << ( ispal(str) ? "\b" : "not") << " a palindrome." << endl;
  return 0;
}
