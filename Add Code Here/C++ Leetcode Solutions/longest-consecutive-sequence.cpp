/*
Problem Statement:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Approach: 

1. Put all the elements in an ordered set 
2. Traverse and check whether the next number is the current+1
3. If true increase the length and when
4. False compare the length with the final ans and assign the maximum value in the final answer.

Testcase 1: 

Input: nums = [100,4,200,1,3,2]
Output: 4

Time Complexity: O(N)
Space Complexity: O(N)

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> n;
        int seq,maxLen=0,ans=0;

        for(auto num:nums){
            n.insert(num);
        }

        seq=*n.begin();

        for(auto s:n){
                if(s==seq){
                maxLen++;
                seq++;
                }
            else {
                ans = max(ans,maxLen);
                seq=s;
                seq++;
                maxLen=1;
            }
        }
        ans = max(ans,maxLen);
        return ans;
    }
};
