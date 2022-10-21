// C Program to draw Pyramid pattern

#include <stdio.h>

int main() {
  int row;
  printf("enter row");
  scanf("%d", &row);
  int temp = row;
  
  for (; row > 0; row--) 
  {
    for (int _ = 0; _ < row; _++) 
    {
      printf(" ");
    }
    for (int star = temp - row; star > 0; star--) 
    {
      printf("* ");
    }
    printf("\n");
  }
}