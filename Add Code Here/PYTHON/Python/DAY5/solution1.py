def binary_search(arr, low, high, x):
    mid = (high + low) // 2
    # Check base case
    if high >= low:
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return mid+1

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if nums[len(nums)-1] < target:
            return len(nums)
        return binary_search(nums, 0, len(nums)-1, target)
