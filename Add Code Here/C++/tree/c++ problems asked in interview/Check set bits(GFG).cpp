Example 1:

Input:
N = 7
Output:
1
Explanation:
Binary for 7 is 111 all the
bits are set so output is 1
Example 2:

Input:
N = 8
Output:
0
Explanation:
Binary for 8 is 1000 all the
bits are not set so output is 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isBitSet() which takes an integer N as input parameters and returns 1 if all the bits in N's binary representation is set or return 0 otherwise.

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)

Solution :

class Solution{
public:
    int isBitSet(int n){
        if(n==0)
            return 0;
        if(((n+1) & n) ==0)
            return 1;
        return 0;
    }
};
