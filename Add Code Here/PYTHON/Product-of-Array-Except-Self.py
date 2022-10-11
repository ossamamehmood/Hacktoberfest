
def productExceptSelf(nums):
    prod, zero_cnt = reduce(lambda a, b: a*(b if b else 1), nums, 1), nums.count(0)
    if zero_cnt > 1: return [0]*len(nums)
    for i, c in enumerate(nums):
        if zero_cnt: nums[i] = 0 if c else prod
        else: nums[i] = prod // c
    return nums
