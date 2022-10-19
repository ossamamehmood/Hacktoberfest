#include <bits/stdc++.h> 
using namespace std;

int INT_BITS = 32;

//Function to left rotate n by d bits 
int leftRotate(int n, unsigned int d) { 
    return (n << d)|(n >> (INT_BITS - d)); 
} 
  
//Function to right rotate n by d bits
int rightRotate(int n, unsigned int d) { 
    return (n >> d)|(n << (INT_BITS - d)); 
} 

int main() { 
    // n is the desired nuber to rotate
    int n = 4; 

    // d is the number of digits by which we want to rotate
    int d = 2; 

    // left rotation of n by d digits
    cout << "Left Rotation of " << n << " by " << d << " is " << leftRotate(n, d)<<"\n";

    //right rotation of n by d digits  
    cout << "Right Rotation of " << n <<" by " << d << " is "<< rightRotate(n, d); 
    
    return 0;
} 