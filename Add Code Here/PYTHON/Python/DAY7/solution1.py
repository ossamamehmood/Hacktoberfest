class Solution:
    def mySqrt(self, x: int) -> int:
        low, high= 0, x
        if high == 1: return 1
        while low<=high:
            mid = low + (high-low)//2
            if mid * mid <= x < (mid+1)*(mid+1):
                return mid
            elif x < mid*mid:
                high = mid - 1
            else:
                low = mid + 1
