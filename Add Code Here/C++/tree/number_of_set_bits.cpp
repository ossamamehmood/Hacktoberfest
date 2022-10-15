#include <bits/stdc++.h> 
using namespace std;

//Count Set Bits
unsigned int countSetBits(unsigned int n) { 
    // c is the number of count of set bits
    unsigned int c = 0; 
    while (n) { 
        n = n & (n-1);
        c++; 
    } 
    return c; 
} 
  
int main() { 
    //n is the desired input
    int n = 17; 

    //Print the number of set bits
    cout <<"Number of set bits are " << countSetBits(n); 
    return 0; 
} 