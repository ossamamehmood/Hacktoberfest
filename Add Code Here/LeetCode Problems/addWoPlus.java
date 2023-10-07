// 371. Sum of Two Integers
// Medium
// Topics
// Companies
// Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = 2, b = 3
// Output: 5
 

// Constraints:

// -1000 <= a, b <= 1000




// Code form here on

class Solution {
    public int getSum(int a, int b) {
        while (b != 0){
        //Calculate the carry
        int carry = a & b;

        //Perform the addition without carry
        a = a ^ b;

        //Carry is shifted by one to the left to add to the next bit
        b = carry << 1;
        }
        
    return a;
    }
}