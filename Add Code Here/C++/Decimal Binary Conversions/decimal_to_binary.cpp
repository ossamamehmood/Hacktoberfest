//Name : Akashdeep-k
//Date : 15/10/2022

// Problem : Write a program to print the binary representation of postive integer.
// 4 --> 100
#include <iostream>
#include <math.h>
using namespace std;
int DecimalToBinary(int n)
{
    int ans = 0, i = 0;
    int bit;
    while (n)
    {
        bit = n & 1;
        if (bit == 1)
        {
            ans = ans + pow(10, i);
        }
        i++;
        n = n >> 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int binary = DecimalToBinary(n);
    cout << binary << endl;
    return 0;
}