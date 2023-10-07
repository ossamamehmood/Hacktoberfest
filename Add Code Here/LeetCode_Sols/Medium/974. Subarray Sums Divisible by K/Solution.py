class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        map = {}
        sum = 0
        count = 0
        for i in range(n):
            sum = sum + nums[i]
            if sum % k == 0: count = count + 1
            rem = sum % k
            if rem < 0: rem = rem + k
            if map.get(rem):
                count = count + map[rem]
                map[rem] = map[rem] + 1
            else:
                map[rem] = 1
        return count
