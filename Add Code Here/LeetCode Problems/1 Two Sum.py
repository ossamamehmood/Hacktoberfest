class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = []  # Initialize an empty list to store the indices of the two numbers

        # Iterate through the elements of the array
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):  # Nested loop to check pairs
                if nums[i] + nums[j] == target:  # Check if the pair sums to the target
                    l.append(i)  # Add the first index to the list
                    l.append(j)  # Add the second index to the list

        return l  # Return the list containing the indices of the two numbers that add up to the target
