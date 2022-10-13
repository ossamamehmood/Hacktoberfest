/*
  DetMatrix_2x2.cpp

  Computes the determinant of a 2x2 matrix.

  Author: Maria De Miglio
  Github: @demisquare
*/

#include <iostream>
using namespace std;

const int n = 2;

void input(int[][n]);
void output(int[][n]);

int main()
{
  int A[n][n];

  cout << "Enter Matrix numbers: " << endl; input(A);

  cout << endl;

  cout << "A :" << endl; output(A);

  cout << endl;

  cout << "det(A): " (A[0][0]*A[1][1])-(A[1][0]*A[0][1]); // det(A)

  return 0;
}

// enter the matrix...
void input(int A[][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> A[i][j];
    }
  }
}

//print the matrix...
void output(int A[][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}
