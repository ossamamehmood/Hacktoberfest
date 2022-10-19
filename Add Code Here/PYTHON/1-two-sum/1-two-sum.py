#Time: O(n)
#Space: O(n)
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # create a dictionary to store the values
        d = {}
        
        # for each value in the array
        for i, value in enumerate(nums):
            # if the value is in the dictionary
            if target - value in d:
                return d[target - value], i
            else:
                d[value] = i
        return None