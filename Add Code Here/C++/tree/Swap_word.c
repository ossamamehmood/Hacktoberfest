#include<stdio.h>
#include<string.h>
int main()
{
  char first[100], second[100], t[100];

  printf("Enter first string\n");
  gets(first);

  printf("Enter second string\n");
  gets(second);

  printf("\nBefore Swapping\n");
  printf("First string: %s\n", first);
  printf("Second string: %s\n\n", second);

  strcpy(t, first);
  strcpy(first, second);
  strcpy(second, t);

  printf("After Swapping\n");
  printf("First string: %s\n", first);
  printf("Second string: %s\n", second);

  return 0;
}
