#include <iostream>
#include <cmath>
using namespace std;
 
// Function to decode given array to get back the original array elements
void decode(int inp[], int m)
{
    // base case
    if (m == 0 || m == 2) {
        return;
    }
 
    // calculate the size of the original array
    int n = (sqrt(8*m + 1) + 1) / 2;
 
    // create an auxiliary array of size `n` to store elements
    // of the original array
    int A[n];
 
    // calculate the first element of the original array
    if (n == 1 || m == 1) {
        A[0] = inp[0];
    }
    else if (n == 2) {
        A[0] = inp[0] - inp[1];
    }
    else {
        A[0] = (inp[0] + inp[1] - inp[n - 1]) / 2;
    }
 
    // calculate the remaining elements of the original array using
    // the first element
    for (int i = 1; i < n; i++) {
        A[i] = inp[i - 1] - A[0];
    }
 
    // print the original array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}
 
int main()
{
    int inp[] = { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 };
    int m = sizeof(inp)/sizeof(inp[0]);
 
    decode(inp, m);
 
    return 0;
}
