We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).
Return the number that I picked.
  
Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1
Example 4:

Input: n = 2, pick = 2
Output: 2
  
Solution :
1. Brute-force method 
class Solution {
public:
    int guessNumber(int n) {
        for(int i=1;i<n;i++)
        {
            if(guess(i)==0)
                return i;
        }
        return n;
    }
};

Time Complexity = O(n)
  
2. Using Binary Search 

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            int res = guess(mid);
            if(res==0)
                return mid;
            else if(res<0)
                end= mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
};

Time Complexity : O(logn)

