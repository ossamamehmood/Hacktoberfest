/*
LEETCODE

1365. How Many Numbers Are Smaller Than the Current Number
Solved
Easy
Topics
Companies
Hint
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
 */

 class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int arr[]=new int[nums.length];
        int i=0,n=nums.length,j=0,count=0;
        for(i=0;i<n;i++){
            count=0;
            for(j=0;j<n;j++){
                if(i==j)    continue;
                if(nums[i]>nums[j])
                    count++;
            }
            arr[i]=count;
        }
        return arr;
    }
}

/*
Runtime
Details
11ms
Beats 8.51%of users with Java

Memory
Details
43.51MB
Beats 61.49%of users with Java
 */