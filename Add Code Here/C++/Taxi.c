#include <stdio.h>
#include <string.h>
int main()
{
  int n, count = 0;
  scanf("%d", &n);
  int arr[n], c[4];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 4; i++)
  {
    c[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    c[arr[i] - 1]++;
  }
  while (c[0] != 0 || c[1] != 0 || c[2] != 0 || c[3] != 0)
  {
    if (c[3] != 0)
    {
      c[3]--;
      count++;
    }
    else if (c[2] != 0)
    {
      if (c[0] != 0)
        c[0]--;
      count++;
      c[2]--;
    }
    else if (c[1] != 0)
    {
      if (c[1] - 2 >= 0)
      {
        c[1] = c[1] - 2;
      }
      else if (c[0] != 0)
      {
        if (c[0] - 2 >= 0)
        {
          c[0] = c[0] - 2;
        }
        else
          c[0]--;
        c[1]--;
      }
      else
        c[1]--;
      count++;
    }
    else
    {
      int sum = 0;
      while (c[0] != 0)
      {
        sum += 1;
        c[0]--;
        if (sum == 4)
          break;
      }
      count++;
    }
  }
  printf("%d", count);
  return 0;
}