class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        temp = [str(i) for i in nums]
        temp.sort(cmp = lambda x, y: cmp(x+y, y+x), reverse = True)
        result = "".join(temp)
        if result[0] == "0":    return "0"      # All "0"s
        else:                   return result
