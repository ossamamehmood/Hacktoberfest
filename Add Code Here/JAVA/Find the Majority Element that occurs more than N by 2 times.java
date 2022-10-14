//Name :- Ayushi Tiwari
// Date:- 05 October 2022

/*
Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

Example 1:
Input Format: N = 3, nums[] = {3,2,3}
Result: 3

Example 2:
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
Result: 2

Moore’s Voting Algorithm

Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.
Majority element count = N/2 + x;
Minority/Other elements = N/2 – x;
Where x is the number of times it occurs after reaching the minimum value N/2.
Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

Approach: 

Initialize 2 variables: 
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through nums array.
  If Count is 0 then initialize the current traversing integer of array as Element 
  If the traversing integer of array and Element are same increase Count by 1
  If they are different decrease Count by 1
The integer present in Element is the result we are expecting 

Code:*/

class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int candidate = 0;

        for (int num: nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate)
                count += 1;
            else count -= 1;
        }

        return candidate;
    }
}

// Time  Complexity: O(N)
// Space Complexity: O(1)
