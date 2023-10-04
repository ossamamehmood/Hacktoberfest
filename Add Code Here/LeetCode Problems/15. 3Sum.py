class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        result = [] # created an empty list
        nums.sort() # we sort the list for operations line binary search
        for i, a in enumerate(nums): # using the enumerate function to iterate over the value of number along with the index
            if i > 0 and a == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1 # using pointers
            while l < r:
                threeSum = a + nums[l] + nums[r] # adding the value at pointers and the value a selected in the for loop
                if threeSum > 0: # if added value is greater than 0 then we reduce the right pointer.
                    r -= 1
                elif threeSum < 0: # if the added value is less than 0 then we add to the left pointer.
                    l += 1
                else:
                    result.append([a, nums[l], nums[r]]) # append the values in the empty list
                    l += 1 # incrementing left pointer
                    while nums[l] == nums[l - 1] and l < r: # checking if the current and previous values of left pointer is same or not
                        l += 1 # if values are same then increment the left pointer
        return result