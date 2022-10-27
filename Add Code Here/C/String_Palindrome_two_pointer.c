#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

int ispal ( char *str )
{
  for( int i = 0, n = strlen(str); i < n; ++i )
  {
    if( str[i] != str[n-1-i] )
      return 0;
  }
  return 1;
}

int main()
{
  char str[MAX_LEN];
  printf("Enter a string: ");
  fflush(stdin);
  scanf("%[^\n]s", str); 
  printf("%s is %s a palindrome", str, ( ispal(str) ? "\b" : "not") );
  return 0;
}
