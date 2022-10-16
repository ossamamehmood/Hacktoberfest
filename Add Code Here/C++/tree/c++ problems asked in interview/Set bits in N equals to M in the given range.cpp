You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
Examples : 
 

Input : N = 1, M = 2, i = 2, j = 4
Output: 9
N = 00000001(Considering 8 bits only)
M = 10 (Binary of 2) For more indexes,
leading zeroes will be considered.
Now set 3 bits from ith index to j in 
the N as in the M.
Bits:-    0 0 0 (0  1  0) 0 1 = 9
Indexes:- 7 6 5  4  3  2  1 0
From index 2 to 4, bits are set according 
to the M.
  
A simple solution is to traverse all bits in N from 0 to 31 and set the bits equals to M in the range from i to j.
An efficient solution is to do following steps.
 

1.Set all the bits after j in a number.
2.Set all the bits before i in a number.
3.Then perform Bitwise Or on both then we get the number with all the bits set except from i to j.
4.Perform Bitwise And with the given N as to set the bits according to the N.
5.Then shift M into the correct position i.e. in the range of i to j.
6.And at the last perform Bitwise Or on (Shifted M and the N modified in 4th step).
7.The result will be N with M as substring from ith to jth bits

Solution :

int updateBits(int n, int m, int i, int j) {
  
int max = ~0; /* All 1’s */
 
int left = max - ((1 << j) - 1);  // 1’s through position j, then 0’s
 
int right = ((1 << i) - 1);  // 1’s after position i
 
int mask = left | right;  // 1’s, with 0s between i and j

return (n & mask) | (m << i);  // Clear i through j, then put m in there
}
