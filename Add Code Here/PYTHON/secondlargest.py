class Solution:
    def findSecondLargest(self,arr, n):
        # max = 0
        # arr = sorted(arr)
        # max = arr[-1]
        # if arr[-1] == arr[-2]:
        #     return arr[-3]
        # return arr[-2]
        max = -1
        smax = max
        for i in range(0,n):
            if arr[i]>max:
                smax = max
                max = arr[i]
            elif arr[i]< max and smax< arr[i]:
                smax = arr[i]
        return smax


if __name__ == "__main__":
    arr = [45,26,78,0,16,52,26,78]
    n = len(arr)
    num = Solution()
    sol = num.findSecondLargest(arr,n)
    print(sol)