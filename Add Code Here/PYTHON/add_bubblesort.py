def sortNumbers(nums):
    x = len(nums)
    for i in range(x):
        for j in range(i+1,x):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
    return nums


nums = [30, 2, 5, 1, 29, 99, 20, 12, 155]
x = sortNumbers(nums)
print(x)