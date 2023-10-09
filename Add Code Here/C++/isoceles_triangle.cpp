#include<iostream>
using namespace std;
int main()
{
  int row, space, i, j;
  cout << "Please enter row: ";
  cin >> row;
  for (i = 1; i <= row; i++)
  {
    for (space = i; space < row; space++)
          cout << " ";
    for (j = 1; j <= i; j++)
          cout << "* ";
    cout << "\n";
  }
  return 0;
}
