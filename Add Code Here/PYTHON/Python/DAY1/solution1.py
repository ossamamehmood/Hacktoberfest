class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for idx, num in enumerate(nums):
            if target - num in d:
                return list([d[target - num], idx])
            d[num] = idx
