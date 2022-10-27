// The Euclidean algorithm is a way to find the greatest common divisor of two positive integers.
// GCD of two numbers is the largest number that divides both of them. 
// A simple way to find GCD is to factorize both numbers and multiply common prime factors.

// C++ program to demonstrate
// Basic Euclidean Algorithm
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
int main()
{
    int a = 20, b = 15;
   
      // Function call
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)<< endl;
    a = 31, b = 10;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)<< endl;
    a = 63, b = 14;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)<< endl;
    
    
    return 0;
}


// Time Complexity: O(Log min(a, b))
// Auxiliary Space: O(Log (min(a,b))