/*
  RecursiveInversePrint.cpp

  Inverts and prints an array recursively.

  Author: Maria De Miglio
  Github: @demisquare
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// fills the array with random numbers...
void fill(int* A, int n)
{
  for(int i = 0; i<n; i++)
  {
    int x = rand()%6+1;
    A[i] = x;
  }
}

// prints the inverted array recursively...
void print(int *A, int i)
{
  if(i>=0)
  {
    cout << A[i] << endl;
    print(A, i-1);
  }

}

int main()
{
  srand(time(0)); //inits seed...

  int n; //size of array...

  cout << "Enter size of array: " << endl;
  cin >> n;

  int* A = new int[n];
  fill(A, n); // random fill...

  cout << "Array: " << endl;
  for(int i = 0; i<n; i++)
    cout << A[i] << endl; // output of array...

  cout << "Inverted array: " << endl;
  print(A, n-1); //inverse output...
}
