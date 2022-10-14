/*
  DetMatrix_3x3.cpp

  Computes the determinant of a 3x3 matrix (rule of Sarrus).

  Author: Maria De Miglio
  Github: @demisquare
*/

#include <iostream>
using namespace std;

const int m = 3; // rows
const int n = 5; // columns + copy of first two columns for rule of Sarrus

void input(int[][n]);
void output(int[][n]);
void copyCol(int[][n]);
int diagPrinc(int[][n], int);
int diagSec(int[][n], int);
int determinant(int[][n]);

int main()
{
  int A[m][n];

  cout << "Enter Matrix numbers : " << endl; input(A);

  cout << endl;

  cout << "A :" << endl; output(A);

  cout << endl;

  cout << "det(A) : " << determinant(A) << endl;

  return 0;
}

// print the matrix without last two columns...
void output(int A[][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

// enter the matrix...
void input(int A[][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> A[i][j];
    }
    copiaCol(A);
  }
}

//duplicate the first two columns for rule of Sarrus...
void copyCol(int A[][n])
{

  for (int i = 0; i < m; i++) //rows
  {
    for (int j = 0; j < m-1; j++) //columns
    {
      A[i][j+3] = A[i][j];

    }
  }
}

// sum main diagnonals...
int diagPrinc(int A[][n], int index)
{
  int dg = 1;

  for (int i = 0; i < m; i++)
  {
    dg*=A[i][i+index];
  }
  return dg;
}

// sum secondary diagnonals...
int diagSec(int A[][n], int index)
{
  int dg = 1;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(i+j == (m-1))
        dg*=A[i][j+index];
    }
  }
  return dg;
}

// computes det(A)...
int determinant(int A[][n])
{
  int det = 0;

  for (int i = 0; i < m; i++)
  {
    det+=diagPrinc(A, i) - diagSec(A, i);
  }

  return det;
}
