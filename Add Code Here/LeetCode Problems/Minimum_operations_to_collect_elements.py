class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        operations = 0
        collections = set()
        for i in range(len(nums)-1,-1,-1):
            operations+=1
            if nums[i]<=k:
                collections.add(nums[i])
            if len(collections)==k:
                 return operations
